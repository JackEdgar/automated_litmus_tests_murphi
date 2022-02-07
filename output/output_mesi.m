/*
  Copyright (c) 2021.  Nicolai Oswald
  Copyright (c) 2021.  University of Edinburgh
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met: redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer;
  redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution;
  neither the name of the copyright holders nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
--Backend/Murphi/MurphiModular/Constants/GenConst
  ---- System access constants
  const
    ENABLE_QS: false;
    VAL_COUNT: 2;
    ADR_COUNT: 2;
  
  ---- System network constants
    O_NET_MAX: 10;
    U_NET_MAX: 10;
  
  ---- SSP declaration constants
    NrCachesL1C1: 3;
  
--Backend/Murphi/MurphiModular/GenTypes
  type
    ----Backend/Murphi/MurphiModular/Types/GenAdrDef
    Address: 0..ADR_COUNT;
    ClValue: 0..VAL_COUNT;
    
    ----Backend/Murphi/MurphiModular/Types/Enums/GenEnums
      ------Backend/Murphi/MurphiModular/Types/Enums/SubEnums/GenAccess
      PermissionType: enum {
        load, 
        store, 
        evict, 
        none
      };
      
      ------Backend/Murphi/MurphiModular/Types/Enums/SubEnums/GenMessageTypes
      MessageType: enum {
        GetSL1C1, 
        GetML1C1, 
        PutSL1C1, 
        Inv_AckL1C1, 
        GetM_Ack_DL1C1, 
        GetS_AckL1C1, 
        WBL1C1, 
        PutML1C1, 
        PutEL1C1, 
        GetM_Ack_ADL1C1, 
        InvL1C1, 
        Put_AckL1C1, 
        Fwd_GetSL1C1, 
        Fwd_GetML1C1
      };
      
      ------Backend/Murphi/MurphiModular/Types/Enums/SubEnums/GenArchEnums
      s_directoryL1C1: enum {
        directoryL1C1_S,
        directoryL1C1_M_GetS,
        directoryL1C1_M,
        directoryL1C1_I,
        directoryL1C1_E_GetS,
        directoryL1C1_E
      };
      
      s_cacheL1C1: enum {
        cacheL1C1_S_store_GetM_Ack_AD,
        cacheL1C1_S_store,
        cacheL1C1_S_evict_x_I,
        cacheL1C1_S_evict,
        cacheL1C1_S,
        cacheL1C1_M_evict_x_I,
        cacheL1C1_M_evict,
        cacheL1C1_M,
        cacheL1C1_I_store_GetM_Ack_AD,
        cacheL1C1_I_store,
        cacheL1C1_I_load,
        cacheL1C1_I,
        cacheL1C1_E_evict_x_I,
        cacheL1C1_E_evict,
        cacheL1C1_E
      };
      
    ----Backend/Murphi/MurphiModular/Types/GenMachineSets
      -- Cluster: C1
      OBJSET_directoryL1C1: enum{directoryL1C1};
      OBJSET_cacheL1C1: scalarset(3);
      C1Machines: union{OBJSET_directoryL1C1, OBJSET_cacheL1C1};
      
      Machines: union{OBJSET_directoryL1C1, OBJSET_cacheL1C1};

        -- Instruction, contains the type, value (if applicable), and address
        -- Model is currently programmed such that loads are performed into the val field
        Instruction: record
            itype: PermissionType;
            val: ClValue;
            adr: Address;
        end;

        -- Threads are sequences of instructions
        thread: array[0..3] of Instruction;
        -- List of all threads, each thread is associated with a cache
        threadlist: array[OBJSET_cacheL1C1] of thread;
        -- Indexes for threads
        threadIndexes: array[OBJSET_cacheL1C1] of record 
        currentIndex: 0..3;
        maxIndex: 0..10000;
        end;
    
    ----Backend/Murphi/MurphiModular/Types/GenCheckTypes
      ------Backend/Murphi/MurphiModular/Types/CheckTypes/GenPermType
        acc_type_obj: multiset[3] of PermissionType;
        PermMonitor: array[Machines] of array[Address] of acc_type_obj;
      
    
    ----Backend/Murphi/MurphiModular/Types/GenMessage
      Message: record
        adr: Address;
        mtype: MessageType;
        src: Machines;
        dst: Machines;
        cl: ClValue;
        acksExpectedL1C1: 0..NrCachesL1C1;
      end;
      
    ----Backend/Murphi/MurphiModular/Types/GenNetwork
      NET_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message;
      NET_Ordered_cnt: array[Machines] of 0..O_NET_MAX;
      NET_Unordered: array[Machines] of multiset[U_NET_MAX] of Message;
    
    ----Backend/Murphi/MurphiModular/Types/GenMachines
      v_cacheL1C1: multiset[NrCachesL1C1] of Machines;
      cnt_v_cacheL1C1: 0..NrCachesL1C1;
      
      ENTRY_directoryL1C1: record
        State: s_directoryL1C1;
        cl: ClValue;
        cacheL1C1: v_cacheL1C1;
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
    --Backend/Murphi/MurphiModular/GenVars
      fwd: NET_Ordered;
      cnt_fwd: NET_Ordered_cnt;
      resp: NET_Ordered;
      cnt_resp: NET_Ordered_cnt;
      req: NET_Ordered;
      cnt_req: NET_Ordered_cnt;
    
    
      g_perm: PermMonitor;
      i_directoryL1C1: OBJ_directoryL1C1;
      i_cacheL1C1: OBJ_cacheL1C1;

    -- Threads, thread list, thread indexes are for litmus tests
    i_thread1: thread;
      i_thread2: thread;
      i_thread3: thread;

    i_threadlist: threadlist;
    i_threadIndexes: threadIndexes;

    -- Used to initialize the thread list, and keep track of total instructions executed
    initializer: 0..3;
    loadedZeroCounter: 0..3;
    instructionsExecuted: 0..6;
  
--Backend/Murphi/MurphiModular/GenFunctions

  ----Backend/Murphi/MurphiModular/Functions/GenResetFunc
    procedure ResetMachine_directoryL1C1();
    begin
      for i:OBJSET_directoryL1C1 do
        for a:Address do
          i_directoryL1C1[i].cb[a].State := directoryL1C1_I;
          i_directoryL1C1[i].cb[a].cl := 0;
          undefine i_directoryL1C1[i].cb[a].cacheL1C1;
          undefine i_directoryL1C1[i].cb[a].ownerL1C1;
    
        endfor;
      endfor;
    end;
    
    procedure ResetMachine_cacheL1C1();
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
    
      procedure ResetMachine_();
      begin
      ResetMachine_directoryL1C1();
      ResetMachine_cacheL1C1();
      
      end;
  ----Backend/Murphi/MurphiModular/Functions/GenEventFunc
  ----Backend/Murphi/MurphiModular/Functions/GenPermFunc
    procedure Clear_perm(adr: Address; m: Machines);
    begin
      alias l_perm_set:g_perm[m][adr] do
          undefine l_perm_set;
      endalias;
    end;
    
    procedure Set_perm(acc_type: PermissionType; adr: Address; m: Machines);
    begin
      alias l_perm_set:g_perm[m][adr] do
      if MultiSetCount(i:l_perm_set, l_perm_set[i] = acc_type) = 0 then
          MultisetAdd(acc_type, l_perm_set);
      endif;
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
    
  
  ----Backend/Murphi/MurphiModular/Functions/GenVectorFunc
    -- .add()
    procedure AddElement_cacheL1C1(var sv:v_cacheL1C1; n:Machines);
    begin
        if MultiSetCount(i:sv, sv[i] = n) = 0 then
          MultiSetAdd(n, sv);
        endif;
    end;
    
    -- .del()
    procedure RemoveElement_cacheL1C1(var sv:v_cacheL1C1; n:Machines);
    begin
        if MultiSetCount(i:sv, sv[i] = n) = 1 then
          MultiSetRemovePred(i:sv, sv[i] = n);
        endif;
    end;
    
    -- .clear()
    procedure ClearVector_cacheL1C1(var sv:v_cacheL1C1;);
    begin
        MultiSetRemovePred(i:sv, true);
    end;
    
    -- .contains()
    function IsElement_cacheL1C1(var sv:v_cacheL1C1; n:Machines) : boolean;
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
    function HasElement_cacheL1C1(var sv:v_cacheL1C1; n:Machines) : boolean;
    begin
        if MultiSetCount(i:sv, true) = 0 then
          return false;
        endif;
    
        return true;
    end;
    
    -- .count()
    function VectorCount_cacheL1C1(var sv:v_cacheL1C1) : cnt_v_cacheL1C1;
    begin
        return MultiSetCount(i:sv, true);
    end;
    
  ----Backend/Murphi/MurphiModular/Functions/GenFIFOFunc
  ----Backend/Murphi/MurphiModular/Functions/GenNetworkFunc
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
    
    procedure Multicast_fwd_v_cacheL1C1(var msg: Message; dst_vect: v_cacheL1C1; src: Machines;);
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
              if cnt_req[dst] >= (O_NET_MAX-4) then
                return false;
              endif;
            endfor;
          endfor;
    
          return true;
    end;
    function resp_network_ready(): boolean;
    begin
          for dst:Machines do
            for src: Machines do
              if cnt_resp[dst] >= (O_NET_MAX-4) then
                return false;
              endif;
            endfor;
          endfor;
    
          return true;
    end;
    function fwd_network_ready(): boolean;
    begin
          for dst:Machines do
            for src: Machines do
              if cnt_fwd[dst] >= (O_NET_MAX-4) then
                return false;
              endif;
            endfor;
          endfor;
    
          return true;
    end;
    function network_ready(): boolean;
    begin
            if !req_network_ready() then
            return false;
          endif;
    
    
          if !resp_network_ready() then
            return false;
          endif;
    
    
          if !fwd_network_ready() then
            return false;
          endif;
    
    
    
      return true;
    end;
    
    procedure Reset_NET_();
    begin
      
      undefine resp;
      for dst:Machines do
          cnt_resp[dst] := 0;
      endfor;
      
      undefine req;
      for dst:Machines do
          cnt_req[dst] := 0;
      endfor;
      
      undefine fwd;
      for dst:Machines do
          cnt_fwd[dst] := 0;
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
      i_thread2[1].adr:=2;

      i_thread3[0].itype:=store;
      i_thread3[0].val:=1;
      i_thread3[0].adr:=2;
      i_thread3[1].itype:=load;
      i_thread3[1].val:=0;
      i_thread3[1].adr:=0;

      i_thread1[2].adr:= 0;
      i_thread2[2].adr:= 0;
      i_thread3[2].adr:= 0;

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
          i_threadlist[m]:= i_thread3;
          initializer:= initializer + 1;
        elsif initializer = 3 then 
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
      if loadedZeroCounter = 3 then error "Litmus test failed" endif;

      -- Reset everything before beginning
      Reset_perm();
      Reset_NET_();
      ResetMachine_();
      Reset_Threads();
    end;
  
  ----Backend/Murphi/MurphiModular/Functions/GenMessageConstrFunc
    function RequestL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
    var Message: Message;
    begin
      Message.adr := adr;
      Message.mtype := mtype;
      Message.src := src;
      Message.dst := dst;
    return Message;
    end;
    
    function AckL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
    var Message: Message;
    begin
      Message.adr := adr;
      Message.mtype := mtype;
      Message.src := src;
      Message.dst := dst;
    return Message;
    end;
    
    function RespL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue) : Message;
    var Message: Message;
    begin
      Message.adr := adr;
      Message.mtype := mtype;
      Message.src := src;
      Message.dst := dst;
      Message.cl := cl;
    return Message;
    end;
    
    function RespAckL1C1(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue; acksExpectedL1C1: 0..NrCachesL1C1) : Message;
    var Message: Message;
    begin
      Message.adr := adr;
      Message.mtype := mtype;
      Message.src := src;
      Message.dst := dst;
      Message.cl := cl;
      Message.acksExpectedL1C1 := acksExpectedL1C1;
    return Message;
    end;
    
  

--Backend/Murphi/MurphiModular/GenStateMachines

  ----Backend/Murphi/MurphiModular/StateMachines/GenAccessStateMachines
    procedure FSM_Access_cacheL1C1_E_evict(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := AckL1C1(adr, PutEL1C1, m, directoryL1C1);
      Send_req(msg, m);
      cbe.State := cacheL1C1_E_evict;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_E_load(adr:Address; m:OBJSET_cacheL1C1);
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Set_perm(load, adr, m);cbe.State := cacheL1C1_E;
      i_threadlist[m][i_threadIndexes[m].currentIndex].val:= cbe.cl;
      if i_threadlist[m][i_threadIndexes[m].currentIndex].val = 0 then loadedZeroCounter:= loadedZeroCounter + 1 endif;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_E_store(adr:Address; m:OBJSET_cacheL1C1);
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Set_perm(store, adr, m);cbe.State := cacheL1C1_M;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_I_load(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr, GetSL1C1, m, directoryL1C1);
      Send_req(msg, m);
      cbe.State := cacheL1C1_I_load;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_I_store(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr, GetML1C1, m, directoryL1C1);
      Send_req(msg, m);
      cbe.acksReceivedL1C1 := 0;
      cbe.State := cacheL1C1_I_store;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_M_evict(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RespL1C1(adr, PutML1C1, m, directoryL1C1, cbe.cl);
      Send_req(msg, m);
      cbe.State := cacheL1C1_M_evict;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_M_load(adr:Address; m:OBJSET_cacheL1C1);
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Set_perm(load, adr, m);cbe.State := cacheL1C1_M;
      i_threadlist[m][i_threadIndexes[m].currentIndex].val:= cbe.cl;
      if i_threadlist[m][i_threadIndexes[m].currentIndex].val = 0 then loadedZeroCounter:= loadedZeroCounter + 1 endif;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_M_store(adr:Address; m:OBJSET_cacheL1C1; v:ClValue);
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Set_perm(store, adr, m);cbe.State := cacheL1C1_M;
      cbe.cl := v;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_S_evict(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr, PutSL1C1, m, directoryL1C1);
      Send_req(msg, m);
      cbe.State := cacheL1C1_S_evict;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_S_load(adr:Address; m:OBJSET_cacheL1C1);
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      Set_perm(load, adr, m);cbe.State := cacheL1C1_S;
      i_threadlist[m][i_threadIndexes[m].currentIndex].val:= cbe.cl;
      if i_threadlist[m][i_threadIndexes[m].currentIndex].val = 0 then loadedZeroCounter:= loadedZeroCounter + 1 endif;
    endalias;
    end;
    
    procedure FSM_Access_cacheL1C1_S_store(adr:Address; m:OBJSET_cacheL1C1);
    var msg: Message;
    begin
    alias cbe: i_cacheL1C1[m].cb[adr] do
      msg := RequestL1C1(adr, GetML1C1, m, directoryL1C1);
      Send_req(msg, m);
      cbe.acksReceivedL1C1 := 0;
      cbe.State := cacheL1C1_S_store;
    endalias;
    end;
    
  ----Backend/Murphi/MurphiModular/StateMachines/GenMessageStateMachines
    function FSM_MSG_directoryL1C1(inmsg:Message; m:OBJSET_directoryL1C1) : boolean;
    var msg: Message;
    begin
      alias adr: inmsg.adr do
      alias cbe: i_directoryL1C1[m].cb[adr] do
    switch cbe.State
      case directoryL1C1_E:
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
          AddElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          AddElement_cacheL1C1(cbe.cacheL1C1, cbe.ownerL1C1);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_E_GetS;
          return true;
        
        case PutEL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_E;
            return true;
          endif;
          if (cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
        
        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (cbe.ownerL1C1 = inmsg.src) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_E;
            return true;
          endif;
        
        case PutSL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_E;
            return true;
          endif;
          if (cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
        
        else return false;
      endswitch;
      
      case directoryL1C1_E_GetS:
      switch inmsg.mtype
        case WBL1C1:
          if (inmsg.src = cbe.ownerL1C1) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;
          if !(inmsg.src = cbe.ownerL1C1) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_E_GetS;
            return true;
          endif;
        
        else return false;
      endswitch;
      
      case directoryL1C1_I:
      switch inmsg.mtype
        case GetML1C1:
          msg := RespAckL1C1(adr,GetM_Ack_ADL1C1,m,inmsg.src,cbe.cl,VectorCount_cacheL1C1(cbe.cacheL1C1));
          Send_resp(msg, m);
          cbe.ownerL1C1 := inmsg.src;
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_M;
          return true;
        
        case GetSL1C1:
          msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          cbe.ownerL1C1 := inmsg.src;
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_E;
          return true;
        
        case PutEL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if (cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
        
        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
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
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
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
          AddElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          AddElement_cacheL1C1(cbe.cacheL1C1, cbe.ownerL1C1);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_M_GetS;
          return true;
        
        case PutEL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (cbe.ownerL1C1 = inmsg.src) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(cbe.ownerL1C1 = inmsg.src) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;
        
        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
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
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
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
          if (inmsg.src = cbe.ownerL1C1) then
            cbe.cl := inmsg.cl;
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;
          if !(inmsg.src = cbe.ownerL1C1) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M_GetS;
            return true;
          endif;
        
        else return false;
      endswitch;
      
      case directoryL1C1_S:
      switch inmsg.mtype
        case GetML1C1:
          if (IsElement_cacheL1C1(cbe.cacheL1C1, inmsg.src)) then
            RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
            msg := RespAckL1C1(adr,GetM_Ack_ADL1C1,m,inmsg.src,cbe.cl,VectorCount_cacheL1C1(cbe.cacheL1C1));
            Send_resp(msg, m);
            msg := AckL1C1(adr,InvL1C1,inmsg.src,inmsg.src);
            Multicast_fwd_v_cacheL1C1(msg, cbe.cacheL1C1, m);
            cbe.ownerL1C1 := inmsg.src;
            ClearVector_cacheL1C1(cbe.cacheL1C1);
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;
          if !(IsElement_cacheL1C1(cbe.cacheL1C1, inmsg.src)) then
            msg := RespAckL1C1(adr,GetM_Ack_ADL1C1,m,inmsg.src,cbe.cl,VectorCount_cacheL1C1(cbe.cacheL1C1));
            Send_resp(msg, m);
            msg := AckL1C1(adr,InvL1C1,inmsg.src,inmsg.src);
            Multicast_fwd_v_cacheL1C1(msg, cbe.cacheL1C1, m);
            cbe.ownerL1C1 := inmsg.src;
            ClearVector_cacheL1C1(cbe.cacheL1C1);
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_M;
            return true;
          endif;
        
        case GetSL1C1:
          msg := RespL1C1(adr,GetS_AckL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          AddElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          Clear_perm(adr, m);
          cbe.State := directoryL1C1_S;
          return true;
        
        case PutEL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if (VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
          if !(VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;
        
        case PutML1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;
          if (VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
            return true;
          endif;
        
        case PutSL1C1:
          msg := AckL1C1(adr,Put_AckL1C1,m,inmsg.src);
          Send_fwd(msg, m);
          RemoveElement_cacheL1C1(cbe.cacheL1C1, inmsg.src);
          if !(VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_S;
            return true;
          endif;
          if (VectorCount_cacheL1C1(cbe.cacheL1C1) = 0) then
            Clear_perm(adr, m);
            cbe.State := directoryL1C1_I;
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
      case cacheL1C1_E:
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
      
      case cacheL1C1_E_evict:
      switch inmsg.mtype
        case Fwd_GetML1C1:
          msg := RespL1C1(adr,GetM_Ack_DL1C1,m,inmsg.src,cbe.cl);
          Send_resp(msg, m);
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_E_evict_x_I;
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
      
      case cacheL1C1_E_evict_x_I:
      switch inmsg.mtype
        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;
        
        else return false;
      endswitch;
      
      case cacheL1C1_I:
      switch inmsg.mtype
        else return false;
      endswitch;
      
      case cacheL1C1_I_load:
      switch inmsg.mtype
        case GetM_Ack_DL1C1:
          cbe.cl := inmsg.cl;
          Set_perm(load, adr, m);
          Clear_perm(adr, m); Set_perm(load, adr, m); Set_perm(store, adr, m);
          cbe.State := cacheL1C1_E;
          return true;
        
        case GetS_AckL1C1:
          cbe.cl := inmsg.cl;
          Set_perm(load, adr, m);
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
            Set_perm(store, adr, m);
            Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;
        
        case GetM_Ack_DL1C1:
          cbe.cl := inmsg.cl;
          Set_perm(store, adr, m);
          Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
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
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Set_perm(store, adr, m);
            Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_I_store_GetM_Ack_AD;
            return true;
          endif;
        
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
          cbe.State := cacheL1C1_M_evict_x_I;
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
      
      case cacheL1C1_M_evict_x_I:
      switch inmsg.mtype
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
          cbe.State := cacheL1C1_S_evict_x_I;
          return true;
        
        case Put_AckL1C1:
          Clear_perm(adr, m);
          cbe.State := cacheL1C1_I;
          return true;
        
        else return false;
      endswitch;
      
      case cacheL1C1_S_evict_x_I:
      switch inmsg.mtype
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
            Set_perm(store, adr, m);
            Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;
        
        case GetM_Ack_DL1C1:
          Set_perm(store, adr, m);
          Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
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
          if (cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Set_perm(store, adr, m);
            Clear_perm(adr, m); Set_perm(store, adr, m); Set_perm(load, adr, m);
            cbe.State := cacheL1C1_M;
            return true;
          endif;
          if !(cbe.acksExpectedL1C1 = cbe.acksReceivedL1C1) then
            Clear_perm(adr, m);
            cbe.State := cacheL1C1_S_store_GetM_Ack_AD;
            return true;
          endif;
        
        else return false;
      endswitch;
      
    endswitch;
    endalias;
    endalias;
    return false;
    end;
    

--Backend/Murphi/MurphiModular/GenResetFunc

  procedure System_Reset();
  begin
  Reset_perm();
  Reset_NET_();
  ResetMachine_();
  end;
  

--Backend/Murphi/MurphiModular/GenRules
  ----Backend/Murphi/MurphiModular/Rules/GenAccessRuleSet
    ruleset m:OBJSET_cacheL1C1 do
      -- Get the address, current thread, cache block, address
      alias currentThread:i_threadlist[m] do
      alias threadIndex:i_threadIndexes[m].currentIndex do
      alias adr:currentThread[threadIndex].adr do
      alias cbe:i_cacheL1C1[m].cb[adr] do
    
      rule "cacheL1C1_E_load"
        cbe.State = cacheL1C1_E 
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load
      ==>
        FSM_Access_cacheL1C1_E_load(adr, m);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 6 then resetEverything(); endif;
      endrule;
    
      rule "cacheL1C1_E_store"
        cbe.State = cacheL1C1_E 
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store
      ==>
        FSM_Access_cacheL1C1_E_store(adr, m);
        
      endrule;
    
      rule "cacheL1C1_E_evict"
        cbe.State = cacheL1C1_E & network_ready() 
      ==>
        FSM_Access_cacheL1C1_E_evict(adr, m);
        
      endrule;
    
      rule "cacheL1C1_I_store"
        cbe.State = cacheL1C1_I & network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store 
      ==>
        FSM_Access_cacheL1C1_I_store(adr, m);
        
      endrule;
    
      rule "cacheL1C1_I_load"
        cbe.State = cacheL1C1_I & network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load 
      ==>
        FSM_Access_cacheL1C1_I_load(adr, m);
        
      endrule;
    
      rule "cacheL1C1_M_evict"
        cbe.State = cacheL1C1_M & network_ready() 
      ==>
        FSM_Access_cacheL1C1_M_evict(adr, m);
        
      endrule;
    
      rule "cacheL1C1_M_store"
        cbe.State = cacheL1C1_M
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store 
      ==>
        FSM_Access_cacheL1C1_M_store(adr, m, currentThread[threadIndex].val);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 6 then resetEverything(); endif;
        
      endrule;
    
      rule "cacheL1C1_M_load"
        cbe.State = cacheL1C1_M
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load 
      ==>
        FSM_Access_cacheL1C1_M_load(adr, m);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 6 then resetEverything(); endif;
        
      endrule;
    
      rule "cacheL1C1_S_load"
        cbe.State = cacheL1C1_S
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = load 
      ==>
        FSM_Access_cacheL1C1_S_load(adr, m);
        i_threadIndexes[m].currentIndex := threadIndex + 1;
        instructionsExecuted:= instructionsExecuted + 1;
        if instructionsExecuted = 6 then resetEverything(); endif;
        
      endrule;
    
      rule "cacheL1C1_S_store"
        cbe.State = cacheL1C1_S & network_ready()
        & threadIndex <= i_threadIndexes[m].maxIndex
        & currentThread[threadIndex].itype = store 
      ==>
        FSM_Access_cacheL1C1_S_store(adr, m);
        
      endrule;
    
      rule "cacheL1C1_S_evict"
        cbe.State = cacheL1C1_S & network_ready() 
      ==>
        FSM_Access_cacheL1C1_S_evict(adr, m);
        
      endrule;
    
    
      endalias;
      endalias;
      endalias;
      endalias;
    endruleset;
    
  ----Backend/Murphi/MurphiModular/Rules/GenEventRuleSet
  ----Backend/Murphi/MurphiModular/Rules/GenNetworkRule
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
    

--Backend/Murphi/MurphiModular/GenStartStates

  startstate
    loadedZeroCounter:= 0;
    resetEverything();
    -- System_Reset();
  endstartstate;

--Backend/Murphi/MurphiModular/GenInvariant
