--RevMurphi.MurphiModular.GenConst
  ---- System access constants
  const
    ENABLE_QS: false;
    
    VAL_COUNT: 1;
    ADR_COUNT: 1;

  ---- System network constants
    O_NET_MAX: 3;
    U_NET_MAX: 3;

  ---- SSP declaration constants
    NrCachesL1C1: 3;

--RevMurphi.MurphiModular.GenTypes
  type
    ----RevMurphi.MurphiModular.Types.GenAdrDef
    -- Two possible addresses, two possibble cache line values
    Address: 0..ADR_COUNT;
    ClValue: 0..VAL_COUNT;

    ---- RevMurphi.MurphiModular.Types.Enums.GenEnums
      ------RevMurphi.MurphiModular.Types.Enums.SubEnums.GenAccess

    -- Instruction types
      PermissionType: enum {
        none,
        load,
        acquire,
        store,
        release,
        fence};

      ------RevMurphi.MurphiModular.Types.Enums.SubEnums.GenMessageTypes
      MessageType: enum {
        GetSL1C1,
        GetML1C1,
        PutSL1C1,
        Inv_AckL1C1,
        GetM_Ack_DL1C1,
        GetS_AckL1C1,
        WBL1C1,
        PutML1C1,
        GetM_Ack_ADL1C1,
        InvL1C1,
        Put_AckL1C1,
        Fwd_GetSL1C1,
        Fwd_GetML1C1
      };

      ------RevMurphi.MurphiModular.Types.Enums.SubEnums.GenArchEnums
      s_cacheL1C1: enum {
        cacheL1C1_S_store_GetM_Ack_AD,
        cacheL1C1_S_store,
        cacheL1C1_S_evict,
        cacheL1C1_S,
        cacheL1C1_M_evict,
        cacheL1C1_M,
        cacheL1C1_I_x_S_evict,
        cacheL1C1_I_x_M_evict,
        cacheL1C1_I_store_GetM_Ack_AD,
        cacheL1C1_I_store,
        cacheL1C1_I_load,
        cacheL1C1_I
      };

      s_directoryL1C1: enum {
        directoryL1C1_S,
        directoryL1C1_M_GetS,
        directoryL1C1_M,
        directoryL1C1_I
      };

    ----RevMurphi.MurphiModular.Types.GenMachineSets
      -- Cluster: C1

      -- One cache level with scalarset for indexing
      OBJSET_cacheL1C1: scalarset(2);
      OBJSET_directoryL1C1: enum{directoryL1C1};

      C1Machines: union{OBJSET_cacheL1C1, OBJSET_directoryL1C1};
      Machines: union{OBJSET_cacheL1C1, OBJSET_directoryL1C1};

      -- Instruction, contains the type, value (if applicable), and address
      -- Model is currently programmed such that loads are performed into the val field
      Instruction: record
        itype: PermissionType;
        val: ClValue;
        adr: Address;
      end;

      -- Threads are sequences of instructions
      thread: array[0..2] of Instruction;
      -- List of all threads, each thread is associated with a cache
      threadlist: array[OBJSET_cacheL1C1] of thread;
      -- Indexes for threads
      threadIndexes: array[OBJSET_cacheL1C1] of record 
        currentIndex: 0..2;
        maxIndex: 0..10000;
      end;

    ----RevMurphi.MurphiModular.Types.GenCheckTypes
      ------RevMurphi.MurphiModular.Types.CheckTypes.GenPermType
        acc_type_obj: multiset[3] of PermissionType;
        PermMonitor: array[Machines] of array[Address] of acc_type_obj;

      ------RevMurphi.MurphiModular.Types.CheckTypes.GenStoreMonitorType
        GlobalStoreMonitor: array[Address] of ClValue;


    ----RevMurphi.MurphiModular.Types.GenMessage

      Message: record
        adr: Address;
        mtype: MessageType;
        src: Machines;
        dst: Machines;
        cl: ClValue;
        acksExpectedL1C1: 0..NrCachesL1C1;
      end;

    ----RevMurphi.MurphiModular.Types.GenNetwork
      NET_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message;
      NET_Ordered_cnt: array[Machines] of 0..O_NET_MAX;
      NET_Unordered: array[Machines] of multiset[U_NET_MAX] of Message;

    ----RevMurphi.MurphiModular.Types.GenMachines
      v_directoryL1C1_cacheL1C1: multiset[NrCachesL1C1] of Machines;
      cnt_v_directoryL1C1_cacheL1C1: 0..NrCachesL1C1;

      ENTRY_directoryL1C1: record
        State: s_directoryL1C1;
        cl: ClValue;
        cacheL1C1: v_directoryL1C1_cacheL1C1;
        ownerL1C1: Machines;
      end;

      MACH_directoryL1C1: record
        cb: array[Address] of ENTRY_directoryL1C1;
      end;

      OBJ_directoryL1C1: array[OBJSET_directoryL1C1] of MACH_directoryL1C1;

      ENTRY_cacheL1C1: record
        State: s_cacheL1C1;
        cl: ClValue;
        acksReceivedL1C1: 0..NrCachesL1C1;
        acksExpectedL1C1: 0..NrCachesL1C1;
      end;

      MACH_cacheL1C1: record
        cb: array[Address] of ENTRY_cacheL1C1;
      end;

      OBJ_cacheL1C1: array[OBJSET_cacheL1C1] of MACH_cacheL1C1;

  var
    --RevMurphi.MurphiModular.GenVars

      fwd: NET_Ordered;
      cnt_fwd: NET_Ordered_cnt;
      resp: NET_Ordered;
      cnt_resp: NET_Ordered_cnt;
      req: NET_Ordered;
      cnt_req: NET_Ordered_cnt;
      g_perm: PermMonitor;
      g_monitor_store: GlobalStoreMonitor;
      i_directoryL1C1: OBJ_directoryL1C1;
      i_cacheL1C1: OBJ_cacheL1C1;

      -- Threads, thread list, thread indexes are for litmus tests
            i_thread1: thread;
      i_thread2: thread;

      i_threadlist: threadlist;
      i_threadIndexes: threadIndexes;

      -- Used to initialize the thread list, and keep track of total instructions executed
      initializer: 0..2;
      loadedZeroCounter: 0..2;
      instructionsExecuted: 0..4;

--RevMurphi.MurphiModular.GenFunctions

  ----RevMurphi.MurphiModular.Functions.GenResetFunc

    -- Reset cache and direcctory, all initialized to invalid and zero values
    procedure Reset_directoryL1C1();
    begin
      for i:OBJSET_directoryL1C1 do
        for a:Address do
          i_directoryL1C1[i].cb[a].State := directoryL1C1_I;
          i_directoryL1C1[i].cb[a].cl := 0;
        endfor;
      endfor;
    end;

    procedure Reset_cacheL1C1();
    begin
      for i:OBJSET_cacheL1C1 do
        for a:Address do
          i_cacheL1C1[i].cb[a].State := cacheL1C1_I;
          i_cacheL1C1[i].cb[a].cl := 0;
          i_cacheL1C1[i].cb[a].acksReceivedL1C1 := 0;
          i_cacheL1C1[i].cb[a].acksExpectedL1C1 := 0;
        endfor;
      endfor;
    end;

  ----RevMurphi.MurphiModular.Functions.GenPermFunc

    -- Clear, reset, reset permissions/state
    procedure Clear_perm(adr: Address; m: Machines);
    begin
      alias l_perm_set:g_perm[m][adr] do
          undefine l_perm_set;
      endalias;
    end;

    procedure Set_perm(acc_type: PermissionType; adr: Address; m: Machines);
    begin
      alias l_perm_set:g_perm[m][adr] do
          MultisetAdd(acc_type, l_perm_set);
      endalias;
    end;

    procedure Reset_perm();
    begin
      for m:Machines do
        for adr:Address do
          Clear_perm(adr, m);
        endfor;
      endfor;
    end;


  ----RevMurphi.MurphiModular.Functions.GenStoreMonitorFunc

    procedure Execute_store_monitor(cb: ClValue; adr: Address);
    begin
      alias cbe: g_monitor_store[adr] do
        if cbe = cb then
          if cbe = VAL_COUNT then
            cbe := 0;
          else
            cbe := cbe + 1;
          endif;
        else
            error "Write linearization failed";
        endif;
      endalias;
    end;

    procedure Reset_global_monitor();
    begin
      for adr:Address do
        g_monitor_store[adr] := 0;
      endfor;
    end;
    
    -- procedure Store(var cbe: ClValue; adr: Address);
    -- begin
    --   Execute_store_monitor(cbe, adr);
    --   if cbe = VAL_COUNT then
    --     cbe:= 0;
    --   else
    --     cbe := cbe + 1;
    --   endif;
    -- end;

  ----RevMurphi.MurphiModular.Functions.GenVectorFunc
    -- .add()
    procedure AddElement_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1; n:Machines);
    begin
        if MultiSetCount(i:sv, sv[i] = n) = 0 then
          MultiSetAdd(n, sv);
        endif;
    end;

    -- .del()
    procedure RemoveElement_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1; n:Machines);
    begin
        if MultiSetCount(i:sv, sv[i] = n) = 1 then
          MultiSetRemovePred(i:sv, sv[i] = n);
        endif;
    end;

    -- .clear()
    procedure ClearVector_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1;);
    begin
        MultiSetRemovePred(i:sv, true);
    end;

    -- .contains()
    function IsElement_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1; n:Machines) : boolean;
    begin
        if MultiSetCount(i:sv, sv[i] = n) = 1 then
          return true;
        elsif MultiSetCount(i:sv, sv[i] = n) = 0 then
          return false;
        else
          Error "Multiple Entries of Sharer in SV multiset";
        endif;
      return false;
    end;

    -- .empty()
    function HasElement_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1; n:Machines) : boolean;
    begin
        if MultiSetCount(i:sv, true) = 0 then
          return false;
        endif;

        return true;
    end;

    -- .count()
    function VectorCount_directoryL1C1_cacheL1C1(var sv:v_directoryL1C1_cacheL1C1) : cnt_v_directoryL1C1_cacheL1C1;
    begin
        return MultiSetCount(i:sv, true);
    end;

  ----RevMurphi.MurphiModular.Functions.GenFIFOFunc
  ----RevMurphi.MurphiModular.Functions.GenNetworkFunc

    procedure Send_fwd(msg:Message; src: Machines;);
      Assert(cnt_fwd[msg.dst] < O_NET_MAX) "Too many messages";
      fwd[msg.dst][cnt_fwd[msg.dst]] := msg;
      cnt_fwd[msg.dst] := cnt_fwd[msg.dst] + 1;
    end;

    procedure Pop_fwd(dst:Machines; src: Machines;);
    begin
      Assert (cnt_fwd[dst] > 0) "Trying to advance empty Q";
      for i := 0 to cnt_fwd[dst]-1 do
        if i < cnt_fwd[dst]-1 then
          fwd[dst][i] := fwd[dst][i+1];
        else
          undefine fwd[dst][i];
        endif;
      endfor;
      cnt_fwd[dst] := cnt_fwd[dst] - 1;
    end;

    procedure Send_resp(msg:Message; src: Machines;);
      Assert(cnt_resp[msg.dst] < O_NET_MAX) "Too many messages";
      resp[msg.dst][cnt_resp[msg.dst]] := msg;
      cnt_resp[msg.dst] := cnt_resp[msg.dst] + 1;
    end;

    procedure Pop_resp(dst:Machines; src: Machines;);
    begin
      Assert (cnt_resp[dst] > 0) "Trying to advance empty Q";
      for i := 0 to cnt_resp[dst]-1 do
        if i < cnt_resp[dst]-1 then
          resp[dst][i] := resp[dst][i+1];
        else
          undefine resp[dst][i];
        endif;
      endfor;
      cnt_resp[dst] := cnt_resp[dst] - 1;
    end;

    procedure Send_req(msg:Message; src: Machines;);
      Assert(cnt_req[msg.dst] < O_NET_MAX) "Too many messages";
      req[msg.dst][cnt_req[msg.dst]] := msg;
      cnt_req[msg.dst] := cnt_req[msg.dst] + 1;
    end;

    procedure Pop_req(dst:Machines; src: Machines;);
    begin
      Assert (cnt_req[dst] > 0) "Trying to advance empty Q";
      for i := 0 to cnt_req[dst]-1 do
        if i < cnt_req[dst]-1 then
          req[dst][i] := req[dst][i+1];
        else
          undefine req[dst][i];
        endif;
      endfor;
      cnt_req[dst] := cnt_req[dst] - 1;
    end;

    procedure Multicast_fwd_C1(var msg: Message; dst_vect: v_directoryL1C1_cacheL1C1; src: Machines;);
    begin
          for n:Machines do
              if n!=msg.src then
                if MultiSetCount(i:dst_vect, dst_vect[i] = n) = 1 then
                  msg.dst := n;
                  Send_fwd(msg, src);
                endif;
              endif;
          endfor;
    end;

    function req_network_ready(): boolean;
    begin
          for dst:Machines do
            for src: Machines do
              if cnt_req[dst] >= (O_NET_MAX-2) then
                return false;
              endif;
            endfor;
          endfor;

          return true;
    end;

    procedure Reset_NET_();
    begin

      undefine fwd;
      for dst:Machines do
          cnt_fwd[dst] := 0;
      endfor;

      undefine req;
      for dst:Machines do
          cnt_req[dst] := 0;
      endfor;

      undefine resp;
      for dst:Machines do
          cnt_resp[dst] := 0;
      endfor;

    end;

    -- Resets the threads to their initial state
    procedure Reset_Threads();
    begin

            i_thread1[0].itype:=store;
      i_thread1[0].val:=1;
      i_thread1[0].adr:=0;
      i_thread1[1].itype:=load;
      i_thread1[1].val:=0;
      i_thread1[1].adr:=1;

      i_thread2[0].itype:=store;
      i_thread2[0].val:=1;
      i_thread2[0].adr:=1;
      i_thread2[1].itype:=load;
      i_thread2[1].val:=0;
      i_thread2[1].adr:=0;

      i_thread1[2].adr:= 0;
      i_thread2[2].adr:= 0;

      initializer:= 0;
      instructionsExecuted:= 0;
      loadedZeroCounter:= 0;

      for m:OBJSET_cacheL1C1 do
        i_threadIndexes[m].currentIndex:= 0;
        if initializer = 0 then 
          i_threadIndexes[m].maxIndex:= 1;
          i_threadlist[m]:= i_thread1;
          initializer:= initializer + 1;
        elsif initializer = 1 then 
          i_threadIndexes[m].maxIndex:= 1;
          i_threadlist[m]:= i_thread2;
          initializer:= initializer + 1;
        elsif initializer = 2 then 
          i_threadIndexes[m].maxIndex:= 1;
          i_threadIndexes[m].currentIndex:= 2;
        endif;
      endfor;

    end;

        -- Called initially, and whenever we have executed all instructions in the litmus test
    -- Therefore, each call will make the model checker explore another series of interleavings of the litmus test
    procedure resetEverything();
    begin
      -- Throws an error if we have violated invariant of the litmus test
      if loadedZeroCounter = 2 then error "Litmus test failed" endif;

      -- Reset everything before beginning
      Reset_perm();
      Reset_global_monitor();
      Reset_NET_();
      Reset_directoryL1C1();
      Reset_cacheL1C1();
      Reset_Threads();
    end;

  ----RevMurphi.MurphiModular.Functions.GenMessageConstrFunc
    function RequestL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
    var msg: Message;
    begin
      msg.adr := adr;
      msg.mtype := mtype;
      msg.src := src;
      msg.dst := dst;
    return msg;
    end;

    function AckL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
    var msg: Message;
    begin
      msg.adr := adr;
      msg.mtype := mtype;
      msg.src := src;
      msg.dst := dst;
    return msg;
    end;

    function RespL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue) : Message;
    var msg: Message;
    begin
      msg.adr := adr;
      msg.mtype := mtype;
      msg.src := src;
      msg.dst := dst;
      msg.cl := cl;
    return msg;
    end;

    function RespAckL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue; acksExpectedL1C1: 0..NrCachesL1C1) : Message;
    var msg: Message;
    begin
      msg.adr := adr;
      msg.mtype := mtype;
      msg.src := src;
      msg.dst := dst;
      msg.cl := cl;
      msg.acksExpectedL1C1 := acksExpectedL1C1;
    return msg;
    end;



--RevMurphi.MurphiModular.GenStateMachines

  ----RevMurphi.MurphiModular.StateMachines.GenMessageStateMachines

    function FSM_MSG_directoryL1C1(inmsg:Message; m:OBJSET_directoryL1C1) : boolean;
    var msg: Message;
    begin
      alias adr: inmsg.adr do
      alias cbe: i_directoryL1C1[m].cb[adr] do
    switch cbe.State
      case directoryL1C1_I:
      switch inmsg.mtype
        case GetML1C1:
          msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          cbe.ownerL1C1 := inmsg.src;
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_M;
          return true;

        case GetSL1C1:
          AddElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          msg := RespL1C1(adr,GetS_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_S;
          return true;

        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          if (cbe.ownerL1C1 = inmsg.src) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;

        case PutSL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if (VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;

        else return false;
      endswitch;

      case directoryL1C1_M:
      switch inmsg.mtype
        case GetML1C1:
          msg := RequestL1C1(adr,Fwd_GetML1C1,inmsg.src,cbe.ownerL1C1);
          Send_fwd(msg, m);
          cbe.ownerL1C1 := inmsg.src;
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_M;
          return true;

        case GetSL1C1:
          msg := RequestL1C1(adr,Fwd_GetSL1C1,inmsg.src,cbe.ownerL1C1);
          Send_fwd(msg, m);
          AddElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          AddElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, cbe.ownerL1C1);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_M_GetS;
          return true;

        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;
          if (cbe.ownerL1C1 = inmsg.src) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;

        case PutSL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;
          if (cbe.ownerL1C1 = inmsg.src) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;

        else return false;
      endswitch;

      case directoryL1C1_M_GetS:
      switch inmsg.mtype
        case WBL1C1:
          if !(inmsg.src = cbe.ownerL1C1) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M_GetS;
            return true;
          endif;
          if (inmsg.src = cbe.ownerL1C1) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;

        else return false;
      endswitch;

      case directoryL1C1_S:
      switch inmsg.mtype
        case GetML1C1:
          if (IsElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src)) then
            RemoveElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
            if !(VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
              msg := RespAckL1C1(adr,GetM_Ack_ADL1C1,m,inmsg.src,cbe.cl,VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1));
              Send_resp(msg, m);
              msg := AckL1C1(adr,InvL1C1,inmsg.src,inmsg.src);
              Multicast_fwd_C1(msg, cbe.cacheL1C1, m);
              cbe.ownerL1C1 := inmsg.src;
              ClearVector_directoryL1C1_cacheL1C1(cbe.cacheL1C1);
              Clear_perm(adr, m);
              cbe.State := directoryL1C1_M;
              return true;
            endif;
            if (VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
              msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
              Send_resp(msg, m);
              cbe.ownerL1C1 := inmsg.src;
              ClearVector_directoryL1C1_cacheL1C1(cbe.cacheL1C1);
              Clear_perm(adr, m);
              cbe.State := directoryL1C1_M;
              return true;
            endif;
          endif;
          if !(IsElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src)) then
            msg := RespAckL1C1(adr,GetM_Ack_ADL1C1,m,inmsg.src,cbe.cl,VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1));
            Send_resp(msg, m);
            msg := AckL1C1(adr,InvL1C1,inmsg.src,inmsg.src);
            Multicast_fwd_C1(msg, cbe.cacheL1C1, m);
            cbe.ownerL1C1 := inmsg.src;
            ClearVector_directoryL1C1_cacheL1C1(cbe.cacheL1C1);
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;

        case GetSL1C1:
          AddElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          msg := RespL1C1(adr,GetS_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_S;
          return true;

        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;

        case PutSL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_directoryL1C1_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(VectorCount_directoryL1C1_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;

        else return false;
      endswitch;

    endswitch;
    endalias;
    endalias;
    return false;
    end;

    function FSM_MSG_cacheL1C1(inmsg:Message; m:OBJSET_cacheL1C1) : boolean;
    var msg: Message;
    begin
      alias adr: inmsg.adr do
      alias cbe: i_cacheL1C1[m].cb[adr] do
    switch cbe.State
      case cacheL1C1_I:
      switch inmsg.mtype
        else return false;
      endswitch;

      case cacheL1C1_I_load:
      switch inmsg.mtype
        case GetS_AckL1C1:
          cbe.cl := inmsg.cl;
          Clear_perm(adr, m); Set_perm(load, adr, m);
          cbe.State := cacheL1C1_S;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_I_store:
      switch inmsg.mtype
        case GetM_Ack_ADL1C1:
          cbe.cl := inmsg.cl;
          cbe.acksExpectedL1C1 := inmsg.acksExpectedL1C1;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_I_store_GetM_Ack_AD;
            return true;
          endif;
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;

        case GetM_Ack_DL1C1:
          cbe.cl := inmsg.cl;
          Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
          cbe.State := cacheL1C1_M;
          return true;

        case Inv_AckL1C1:
          cbe.acksReceivedL1C1 := cbe.acksReceivedL1C1+1;
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I_store;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_I_store_GetM_Ack_AD:
      switch inmsg.mtype
        case Inv_AckL1C1:
          cbe.acksReceivedL1C1 := cbe.acksReceivedL1C1+1;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_I_store_GetM_Ack_AD;
            return true;
          endif;
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;

        else return false;
      endswitch;

      case cacheL1C1_I_x_M_evict:
      switch inmsg.mtype
        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_I_x_S_evict:
      switch inmsg.mtype
        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_M:
      switch inmsg.mtype
        case Fwd_GetML1C1:
          msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        case Fwd_GetSL1C1:
          msg := RespL1C1(adr,GetS_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          msg := RespL1C1(adr,WBL1C1,m,directoryL1C1,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m); Set_perm(load, adr, m);
          cbe.State := cacheL1C1_S;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_M_evict:
      switch inmsg.mtype
        case Fwd_GetML1C1:
          msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I_x_M_evict;
          return true;

        case Fwd_GetSL1C1:
          msg := RespL1C1(adr,GetS_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          msg := RespL1C1(adr,WBL1C1,m,directoryL1C1,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_S_evict;
          return true;

        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_S:
      switch inmsg.mtype
        case InvL1C1:
          msg := RespL1C1(adr,Inv_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_S_evict:
      switch inmsg.mtype
        case InvL1C1:
          msg := RespL1C1(adr,Inv_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I_x_S_evict;
          return true;

        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_S_store:
      switch inmsg.mtype
        case GetM_Ack_ADL1C1:
          cbe.acksExpectedL1C1 := inmsg.acksExpectedL1C1;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_S_store_GetM_Ack_AD;
            return true;
          endif;
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;

        case GetM_Ack_DL1C1:
          Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
          cbe.State := cacheL1C1_M;
          return true;

        case InvL1C1:
          msg := RespL1C1(adr,Inv_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I_store;
          return true;

        case Inv_AckL1C1:
          cbe.acksReceivedL1C1 := cbe.acksReceivedL1C1+1;
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_S_store;
          return true;

        else return false;
      endswitch;

      case cacheL1C1_S_store_GetM_Ack_AD:
      switch inmsg.mtype
        case Inv_AckL1C1:
          cbe.acksReceivedL1C1 := cbe.acksReceivedL1C1+1;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_S_store_GetM_Ack_AD;
            return true;
          endif;
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;

        else return false;
      endswitch;

    endswitch;
    endalias;
    endalias;
    return false;
    end;

  ----RevMurphi.MurphiModular.StateMachines.GenAccessStateMachines

    -- Loads, stores, and evicts for different states
    procedure FSM_Access_cacheL1C1_I_load(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr,GetSL1C1,m,directoryL1C1);
      Send_req(msg, m);
      Clear_perm(adr, m);
      cbe.State := cacheL1C1_I_load;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_I_store(adr:Address; m:OBJSET_cacheL1C1; v:ClValue);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr,GetML1C1,m,directoryL1C1);
      Send_req(msg, m);
      cbe.acksReceivedL1C1 := 0;
      Clear_perm(adr, m);
      cbe.State := cacheL1C1_I_store;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_M_evict(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RespL1C1(adr,PutML1C1,m,directoryL1C1,cbe.cl);
      Send_req(msg, m);
      Clear_perm(adr, m);
      cbe.State := cacheL1C1_M_evict;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_M_load(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
      cbe.State := cacheL1C1_M;
      i_threadlist[m][i_threadIndexes[m].currentIndex].val:= cbe.cl;
      if i_threadlist[m][i_threadIndexes[m].currentIndex].val = 0 then loadedZeroCounter:= loadedZeroCounter + 1 endif;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_M_store(adr:Address; m:OBJSET_cacheL1C1; v:ClValue);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
      cbe.State := cacheL1C1_M;
      Execute_store_monitor(cbe.cl, adr);
      cbe.cl := v;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_S_evict(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr,PutSL1C1,m,directoryL1C1);
      Send_req(msg, m);
      Clear_perm(adr, m);
      cbe.State := cacheL1C1_S_evict;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_S_load(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Clear_perm(adr, m); Set_perm(load, adr, m);
      cbe.State := cacheL1C1_S;
      i_threadlist[m][i_threadIndexes[m].currentIndex].val:= cbe.cl;
      if i_threadlist[m][i_threadIndexes[m].currentIndex].val = 0 then loadedZeroCounter:= loadedZeroCounter + 1 endif;
    endalias;
    end;

    procedure FSM_Access_cacheL1C1_S_store(adr:Address; m:OBJSET_cacheL1C1; v:ClValue);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr,GetML1C1,m,directoryL1C1);
      Send_req(msg, m);
      cbe.acksReceivedL1C1 := 0;
      Clear_perm(adr, m);
      cbe.State := cacheL1C1_S_store;
    endalias;
    end;

  ----RevMurphi.MurphiModular.StateMachines.GenAccessRuleSet

    -- Random selection over the scalarset
    ruleset m:OBJSET_cacheL1C1 do
      -- Get the address, current thread, cache block, address
      alias currentThread:i_threadlist[m] do
      alias threadIndex:i_threadIndexes[m].currentIndex do
      alias adr:currentThread[threadIndex].adr do
      alias cbe:i_cacheL1C1[m].cb[adr] do

      -- Each rule has a guard, then executes if guard is true
      rule "cacheL1C1_I_load"
        cbe.State = cacheL1C1_I
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load
      ==>
        FSM_Access_cacheL1C1_I_load(adr, m);
      endrule;

      rule "cacheL1C1_I_store"
        cbe.State = cacheL1C1_I
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store
      ==>
        FSM_Access_cacheL1C1_I_store(adr, m, currentThread[threadIndex].val);
      endrule;

      rule "cacheL1C1_M_load"
        cbe.State = cacheL1C1_M
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load
      ==>
        FSM_Access_cacheL1C1_M_load(adr, m);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 4 then resetEverything(); endif;
      endrule;

      rule "cacheL1C1_M_evict"
        cbe.State = cacheL1C1_M
        & req_network_ready()
      ==>
        FSM_Access_cacheL1C1_M_evict(adr, m);
      endrule;

      rule "cacheL1C1_M_store"
        cbe.State = cacheL1C1_M
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store
      ==>
        FSM_Access_cacheL1C1_M_store(adr, m, currentThread[threadIndex].val);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 4 then resetEverything(); endif;
      endrule;

      rule "cacheL1C1_S_load"
        cbe.State = cacheL1C1_S
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load
      ==>
        FSM_Access_cacheL1C1_S_load(adr, m);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 4 then resetEverything(); endif;
      endrule;

      rule "cacheL1C1_S_evict"
        cbe.State = cacheL1C1_S
        & req_network_ready()
      ==>
        FSM_Access_cacheL1C1_S_evict(adr, m);
      endrule;

      rule "cacheL1C1_S_store"
        cbe.State = cacheL1C1_S
        & req_network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store
      ==>
        FSM_Access_cacheL1C1_S_store(adr, m, currentThread[threadIndex].val);
      endrule;

      endalias;
      endalias;
      endalias;
      endalias;
    endruleset;

--RevMurphi.MurphiModular.GenNetworkRules

  ----RevMurphi.MurphiModular.NetworkRules.GenNetworkRule
    ruleset dst:Machines do
        ruleset src: Machines do
            alias msg:fwd[dst][0] do
              rule "Receive fwd"
                cnt_fwd[dst] > 0
              ==>
            if IsMember(dst, OBJSET_directoryL1C1) then
              if FSM_MSG_directoryL1C1(msg, dst) then
                  Pop_fwd(dst, src);
              endif;
            elsif IsMember(dst, OBJSET_cacheL1C1) then
              if FSM_MSG_cacheL1C1(msg, dst) then
                  Pop_fwd(dst, src);
              endif;
            else error "unknown machine";
            endif;

              endrule;
            endalias;
        endruleset;
    endruleset;

    ruleset dst:Machines do
        ruleset src: Machines do
            alias msg:req[dst][0] do
              rule "Receive req"
                cnt_req[dst] > 0
              ==>
            if IsMember(dst, OBJSET_directoryL1C1) then
              if FSM_MSG_directoryL1C1(msg, dst) then
                  Pop_req(dst, src);
              endif;
            elsif IsMember(dst, OBJSET_cacheL1C1) then
              if FSM_MSG_cacheL1C1(msg, dst) then
                  Pop_req(dst, src);
              endif;
            else error "unknown machine";
            endif;

              endrule;
            endalias;
        endruleset;
    endruleset;

    ruleset dst:Machines do
        ruleset src: Machines do
            alias msg:resp[dst][0] do
              rule "Receive resp"
                cnt_resp[dst] > 0
              ==>
            if IsMember(dst, OBJSET_directoryL1C1) then
              if FSM_MSG_directoryL1C1(msg, dst) then
                  Pop_resp(dst, src);
              endif;
            elsif IsMember(dst, OBJSET_cacheL1C1) then
              if FSM_MSG_cacheL1C1(msg, dst) then
                  Pop_resp(dst, src);
              endif;
            else error "unknown machine";
            endif;

              endrule;
            endalias;
        endruleset;
    endruleset;

--RevMurphi.MurphiModular.GenStartStates

  -- Initial state / setup before execution
  startstate

    -- Resets everything to the initial state, while setting one initial value up manually beforehand to prevent litmus test issues
    loadedZeroCounter:= 0;
    resetEverything();

  endstartstate;

--RevMurphi.MurphiModular.GenInvariant
  invariant "Exclusive store check"
      forall a:Address do
          forall m1:Machines do
          forall m2:Machines do
          ( m1 != m2
            & MultiSetCount(i:g_perm[m1][a], g_perm[m1][a][i] = store) > 0)
          ->
            MultiSetCount(i:g_perm[m2][a], g_perm[m2][a][i] = store) = 0
          endforall
          endforall
      endforall;

  invariant "Store excludes load check"
      forall a:Address do
          forall m1:Machines do
          forall m2:Machines do
          ( m1 != m2
            & MultiSetCount(i:g_perm[m1][a], g_perm[m1][a][i] = store) > 0)
          ->
            MultiSetCount(i:g_perm[m2][a], g_perm[m2][a][i] = load) = 0
          endforall
          endforall
      endforall;