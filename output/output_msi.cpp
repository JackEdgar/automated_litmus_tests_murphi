/******************************
  Program "output_msi.m" compiled by "Caching Murphi Release 5.4.9.1"

  Murphi Last Compiled date: "Sep 30 2021"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9.1"
#define MURPHI_DATE "Sep 30 2021"
#define PROTOCOL_NAME "output_msi"
#define BITS_IN_WORLD 3648
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_Address: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Address& val) { return mu__byte::operator=((int) val); };
  mu_1_Address (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_Address (void): mu__byte(0, 2, 2) {};
  mu_1_Address (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Address mu_1_Address_undefined_var;

class mu_1_ClValue: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ClValue& val) { return mu__byte::operator=((int) val); };
  mu_1_ClValue (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_ClValue (void): mu__byte(0, 2, 2) {};
  mu_1_ClValue (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_ClValue mu_1_ClValue_undefined_var;

class mu_1_PermissionType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_PermissionType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_PermissionType& val)
  {
    if (val.defined())
      return ( s << mu_1_PermissionType::values[ int(val) - 1] );
    else return ( s << "Undefined" );
  };

  mu_1_PermissionType (const char *name, int os): mu__byte(1, 6, 3, name, os) {};
  mu_1_PermissionType (void): mu__byte(1, 6, 3) {};
  mu_1_PermissionType (int val): mu__byte(1, 6, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -1]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -1] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_PermissionType::values[] = {"none","load","acquire","store","release","fence",NULL };

/*** end of enum declaration ***/
mu_1_PermissionType mu_1_PermissionType_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (const char *name, int os): mu__byte(7, 19, 4, name, os) {};
  mu_1_MessageType (void): mu__byte(7, 19, 4) {};
  mu_1_MessageType (int val): mu__byte(7, 19, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_MessageType::values[] = {"GetSL1C1","GetML1C1","PutSL1C1","Inv_AckL1C1","GetM_Ack_DL1C1","GetS_AckL1C1","WBL1C1","PutML1C1","GetM_Ack_ADL1C1","InvL1C1","Put_AckL1C1","Fwd_GetSL1C1","Fwd_GetML1C1",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_s_cacheL1C1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_s_cacheL1C1& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_s_cacheL1C1& val)
  {
    if (val.defined())
      return ( s << mu_1_s_cacheL1C1::values[ int(val) - 20] );
    else return ( s << "Undefined" );
  };

  mu_1_s_cacheL1C1 (const char *name, int os): mu__byte(20, 31, 4, name, os) {};
  mu_1_s_cacheL1C1 (void): mu__byte(20, 31, 4) {};
  mu_1_s_cacheL1C1 (int val): mu__byte(20, 31, 4, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -20]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -20] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_s_cacheL1C1::values[] = {"cacheL1C1_S_store_GetM_Ack_AD","cacheL1C1_S_store","cacheL1C1_S_evict","cacheL1C1_S","cacheL1C1_M_evict","cacheL1C1_M","cacheL1C1_I_x_S_evict","cacheL1C1_I_x_M_evict","cacheL1C1_I_store_GetM_Ack_AD","cacheL1C1_I_store","cacheL1C1_I_load","cacheL1C1_I",NULL };

/*** end of enum declaration ***/
mu_1_s_cacheL1C1 mu_1_s_cacheL1C1_undefined_var;

class mu_1_s_directoryL1C1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_s_directoryL1C1& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_s_directoryL1C1& val)
  {
    if (val.defined())
      return ( s << mu_1_s_directoryL1C1::values[ int(val) - 32] );
    else return ( s << "Undefined" );
  };

  mu_1_s_directoryL1C1 (const char *name, int os): mu__byte(32, 35, 3, name, os) {};
  mu_1_s_directoryL1C1 (void): mu__byte(32, 35, 3) {};
  mu_1_s_directoryL1C1 (int val): mu__byte(32, 35, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -32]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -32] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_s_directoryL1C1::values[] = {"directoryL1C1_S","directoryL1C1_M_GetS","directoryL1C1_M","directoryL1C1_I",NULL };

/*** end of enum declaration ***/
mu_1_s_directoryL1C1 mu_1_s_directoryL1C1_undefined_var;

class mu_1_OBJSET_cacheL1C1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_OBJSET_cacheL1C1& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_OBJSET_cacheL1C1& val)
    {
      if (val.defined())
	return ( s << mu_1_OBJSET_cacheL1C1::values[ int(val) - 36 ] );
      else
	return ( s << "Undefined" );
    };

  mu_1_OBJSET_cacheL1C1 (const char *name, int os): mu__byte(36, 38, 2, name, os) {};
  mu_1_OBJSET_cacheL1C1 (void): mu__byte(36, 38, 2) {};
  mu_1_OBJSET_cacheL1C1 (int val): mu__byte(36, 38, 2, "Parameter or function result.", 0)
    { operator=(val); };
  const char * Name() { return values[ value() -36]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 36] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_OBJSET_cacheL1C1& a, mu_1_OBJSET_cacheL1C1& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
const char *mu_1_OBJSET_cacheL1C1::values[] =
  { "OBJSET_cacheL1C1_1","OBJSET_cacheL1C1_2","OBJSET_cacheL1C1_3",NULL };

/*** end scalarset declaration ***/
mu_1_OBJSET_cacheL1C1 mu_1_OBJSET_cacheL1C1_undefined_var;

class mu_1_OBJSET_directoryL1C1: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_OBJSET_directoryL1C1& val) { return value(val.value()); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_OBJSET_directoryL1C1& val)
  {
    if (val.defined())
      return ( s << mu_1_OBJSET_directoryL1C1::values[ int(val) - 39] );
    else return ( s << "Undefined" );
  };

  mu_1_OBJSET_directoryL1C1 (const char *name, int os): mu__byte(39, 39, 1, name, os) {};
  mu_1_OBJSET_directoryL1C1 (void): mu__byte(39, 39, 1) {};
  mu_1_OBJSET_directoryL1C1 (int val): mu__byte(39, 39, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  const char * Name() { return values[ value() -39]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -39] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

const char *mu_1_OBJSET_directoryL1C1::values[] = {"directoryL1C1",NULL };

/*** end of enum declaration ***/
mu_1_OBJSET_directoryL1C1 mu_1_OBJSET_directoryL1C1_undefined_var;

class mu_1_C1Machines: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_C1Machines& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_C1Machines& val)
    {
      if (val.defined())
	return ( s << mu_1_C1Machines::values[ val.indexvalue() ] );
      else
	return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_C1Machines (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_C1Machines (void): mu__byte(0, 3, 3) {};
  mu_1_C1Machines (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 36) && (value() <= 38)) return (value() - 36);
    if ((value() >= 39) && (value() <= 39)) return (value() - 36);
  return 0;
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 2) return value(val+36);
    if (val >= 3 && val <= 3) return value(val+36);
  return 0;
  };
  const char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_C1Machines& a, mu_1_C1Machines& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
const char *mu_1_C1Machines::values[] = {"OBJSET_cacheL1C1_1","OBJSET_cacheL1C1_2","OBJSET_cacheL1C1_3","directoryL1C1",NULL };

/*** end union declaration ***/
mu_1_C1Machines mu_1_C1Machines_undefined_var;

class mu_1_Machines: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Machines& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static const char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Machines& val)
    {
      if (val.defined())
	return ( s << mu_1_Machines::values[ val.indexvalue() ] );
      else
	return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Machines (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_Machines (void): mu__byte(0, 3, 3) {};
  mu_1_Machines (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 36) && (value() <= 38)) return (value() - 36);
    if ((value() >= 39) && (value() <= 39)) return (value() - 36);
  return 0;
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 2) return value(val+36);
    if (val >= 3 && val <= 3) return value(val+36);
  return 0;
  };
  const char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Machines& a, mu_1_Machines& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
const char *mu_1_Machines::values[] = {"OBJSET_cacheL1C1_1","OBJSET_cacheL1C1_2","OBJSET_cacheL1C1_3","directoryL1C1",NULL };

/*** end union declaration ***/
mu_1_Machines mu_1_Machines_undefined_var;

class mu_1_Instruction
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_PermissionType mu_itype;
  mu_1_ClValue mu_val;
  mu_1_Address mu_adr;
  mu_1_Instruction ( const char *n, int os ) { set_self(n,os); };
  mu_1_Instruction ( void ) {};

  virtual ~mu_1_Instruction(); 
friend int CompareWeight(mu_1_Instruction& a, mu_1_Instruction& b)
  {
    int w;
    w = CompareWeight(a.mu_itype, b.mu_itype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Instruction& a, mu_1_Instruction& b)
  {
    int w;
    w = Compare(a.mu_itype, b.mu_itype);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_itype.MultisetSort();
    mu_val.MultisetSort();
    mu_adr.MultisetSort();
  }
  void print_statistic()
  {
    mu_itype.print_statistic();
    mu_val.print_statistic();
    mu_adr.print_statistic();
  }
  void clear() {
    mu_itype.clear();
    mu_val.clear();
    mu_adr.clear();
 };
  void undefine() {
    mu_itype.undefine();
    mu_val.undefine();
    mu_adr.undefine();
 };
  void reset() {
    mu_itype.reset();
    mu_val.reset();
    mu_adr.reset();
 };
  void print() {
    mu_itype.print();
    mu_val.print();
    mu_adr.print();
  };
  void print_diff(state *prevstate) {
    mu_itype.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_adr.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_itype.to_state(thestate);
    mu_val.to_state(thestate);
    mu_adr.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Instruction& operator= (const mu_1_Instruction& from) {
    mu_itype.value(from.mu_itype.value());
    mu_val.value(from.mu_val.value());
    mu_adr.value(from.mu_adr.value());
    return *this;
  };
};

  void mu_1_Instruction::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Instruction::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Instruction::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_itype.set_self_2(name, ".itype", os + 0 ); else mu_itype.set_self_2(NULL, NULL, 0);
  if (name) mu_val.set_self_2(name, ".val", os + 8 ); else mu_val.set_self_2(NULL, NULL, 0);
  if (name) mu_adr.set_self_2(name, ".adr", os + 16 ); else mu_adr.set_self_2(NULL, NULL, 0);
}

mu_1_Instruction::~mu_1_Instruction()
{
}

/*** end record declaration ***/
mu_1_Instruction mu_1_Instruction_undefined_var;

class mu__subrange_14: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_14& val) { return mu__byte::operator=((int) val); };
  mu__subrange_14 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu__subrange_14 (void): mu__byte(0, 3, 3) {};
  mu__subrange_14 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_14 mu__subrange_14_undefined_var;

class mu_1_thread
{
 public:
  mu_1_Instruction array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_thread (const char *n, int os) { set_self(n, os); };
  mu_1_thread ( void ) {};
  virtual ~mu_1_thread ();
  mu_1_Instruction& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 3 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1_thread& operator= (const mu_1_thread& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_thread& a, mu_1_thread& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_thread& a, mu_1_thread& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_thread::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_thread::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_thread::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 4; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 24 + os);
    delete[] s;
  }
};
mu_1_thread::~mu_1_thread()
{
}
/*** end array declaration ***/
mu_1_thread mu_1_thread_undefined_var;

class mu_1_threadlist
{
 public:
  mu_1_thread array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_threadlist (const char *n, int os) { set_self(n, os); };
  mu_1_threadlist ( void ) {};
  virtual ~mu_1_threadlist ();
  mu_1_thread& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - 36 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: OBJSET_cacheL1C1 is internally represented from 36 to 38.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 36 ];
#endif
  };
  mu_1_threadlist& operator= (const mu_1_threadlist& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_threadlist& a, mu_1_threadlist& b)
  {
    return 0;
  }
friend int Compare(mu_1_threadlist& a, mu_1_threadlist& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_threadlist::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_threadlist::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_threadlist::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_threadlist::~mu_1_threadlist()
{
}
/*** end array declaration ***/
mu_1_threadlist mu_1_threadlist_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_0& val) { return mu__byte::operator=((int) val); };
  mu_1__type_0 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(0, 3, 3) {};
  mu_1__type_0 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1__type_1: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1__type_1& val) { return mu__long::operator=((int) val); };
  mu_1__type_1 (const char *name, int os): mu__long(0, 10000, 14, name, os) {};
  mu_1__type_1 (void): mu__long(0, 10000, 14) {};
  mu_1__type_1 (int val): mu__long(0, 10000, 14, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_1 mu_1__type_1_undefined_var;

class mu_1__type_2
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_0 mu_currentIndex;
  mu_1__type_1 mu_maxIndex;
  mu_1__type_2 ( const char *n, int os ) { set_self(n,os); };
  mu_1__type_2 ( void ) {};

  virtual ~mu_1__type_2(); 
friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = CompareWeight(a.mu_currentIndex, b.mu_currentIndex);
    if (w!=0) return w;
    w = CompareWeight(a.mu_maxIndex, b.mu_maxIndex);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    w = Compare(a.mu_currentIndex, b.mu_currentIndex);
    if (w!=0) return w;
    w = Compare(a.mu_maxIndex, b.mu_maxIndex);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_currentIndex.MultisetSort();
    mu_maxIndex.MultisetSort();
  }
  void print_statistic()
  {
    mu_currentIndex.print_statistic();
    mu_maxIndex.print_statistic();
  }
  void clear() {
    mu_currentIndex.clear();
    mu_maxIndex.clear();
 };
  void undefine() {
    mu_currentIndex.undefine();
    mu_maxIndex.undefine();
 };
  void reset() {
    mu_currentIndex.reset();
    mu_maxIndex.reset();
 };
  void print() {
    mu_currentIndex.print();
    mu_maxIndex.print();
  };
  void print_diff(state *prevstate) {
    mu_currentIndex.print_diff(prevstate);
    mu_maxIndex.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_currentIndex.to_state(thestate);
    mu_maxIndex.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1__type_2& operator= (const mu_1__type_2& from) {
    mu_currentIndex.value(from.mu_currentIndex.value());
    mu_maxIndex.value(from.mu_maxIndex.value());
    return *this;
  };
};

  void mu_1__type_2::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_currentIndex.set_self_2(name, ".currentIndex", os + 0 ); else mu_currentIndex.set_self_2(NULL, NULL, 0);
  if (name) mu_maxIndex.set_self_2(name, ".maxIndex", os + 8 ); else mu_maxIndex.set_self_2(NULL, NULL, 0);
}

mu_1__type_2::~mu_1__type_2()
{
}

/*** end record declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1_threadIndexes
{
 public:
  mu_1__type_2 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_threadIndexes (const char *n, int os) { set_self(n, os); };
  mu_1_threadIndexes ( void ) {};
  virtual ~mu_1_threadIndexes ();
  mu_1__type_2& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - 36 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: OBJSET_cacheL1C1 is internally represented from 36 to 38.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 36 ];
#endif
  };
  mu_1_threadIndexes& operator= (const mu_1_threadIndexes& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_threadIndexes& a, mu_1_threadIndexes& b)
  {
    return 0;
  }
friend int Compare(mu_1_threadIndexes& a, mu_1_threadIndexes& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_threadIndexes::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_threadIndexes::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_threadIndexes::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 40 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 40 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 40 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_threadIndexes::~mu_1_threadIndexes()
{
}
/*** end array declaration ***/
mu_1_threadIndexes mu_1_threadIndexes_undefined_var;

/*** begin multiset declaration ***/
class mu_1_acc_type_obj_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_acc_type_obj_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1_acc_type_obj_id () : mu__byte(0,2,0) {};
  mu_1_acc_type_obj_id (int val) : mu__byte(0,2,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1_acc_type_obj
{
 public:
  mu_1_PermissionType array[ 3 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 3 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_acc_type_obj (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1_acc_type_obj ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1_acc_type_obj ();
  mu_1_PermissionType& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 2) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1_acc_type_obj& operator= (const mu_1_acc_type_obj& from)
  {
    for (int i = 0; i < 3; i++)
    {
        array[i].value(from.array[i].value());
        valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1_acc_type_obj& a, mu_1_acc_type_obj& b)
  {
    return 0;
  }
friend int Compare(mu_1_acc_type_obj& a, mu_1_acc_type_obj& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1_acc_type_obj_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 3; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 3; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_PermissionType &element)
  {
    update_size();
    if (current_size >= 3) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 3; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1_acc_type_obj_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_PermissionType temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 3; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 3; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 3; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1_acc_type_obj::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_acc_type_obj::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_acc_type_obj::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 3; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os); else array[i].set_self(NULL, 0);
  k = os + i * 8;
  for(i = 0; i < 3; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1_acc_type_obj::~mu_1_acc_type_obj()
{
}
/*** end multiset declaration ***/
mu_1_acc_type_obj mu_1_acc_type_obj_undefined_var;

class mu_1__type_3
{
 public:
  mu_1_acc_type_obj array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_3 (const char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1_acc_type_obj& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 48 + os);
    delete[] s;
  }
};
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1_PermMonitor
{
 public:
  mu_1__type_3 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_PermMonitor (const char *n, int os) { set_self(n, os); };
  mu_1_PermMonitor ( void ) {};
  virtual ~mu_1_PermMonitor ();
  mu_1__type_3& operator[] (int index) /* const */
  {
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - (36) ];
    if ( ( index >= 39 ) && ( index <= 39 ) )
      return array[ index - (36) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_PermMonitor& operator= (const mu_1_PermMonitor& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_PermMonitor& a, mu_1_PermMonitor& b)
  {
    return 0;
  }
friend int Compare(mu_1_PermMonitor& a, mu_1_PermMonitor& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_PermMonitor::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_PermMonitor::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_PermMonitor::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directoryL1C1", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_PermMonitor::~mu_1_PermMonitor()
{
}
/*** end array declaration ***/
mu_1_PermMonitor mu_1_PermMonitor_undefined_var;

class mu_1_GlobalStoreMonitor
{
 public:
  mu_1_ClValue array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_GlobalStoreMonitor (const char *n, int os) { set_self(n, os); };
  mu_1_GlobalStoreMonitor ( void ) {};
  virtual ~mu_1_GlobalStoreMonitor ();
  mu_1_ClValue& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1_GlobalStoreMonitor& operator= (const mu_1_GlobalStoreMonitor& from)
  {
    for (int i = 0; i < 3; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_GlobalStoreMonitor& a, mu_1_GlobalStoreMonitor& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_GlobalStoreMonitor& a, mu_1_GlobalStoreMonitor& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_GlobalStoreMonitor::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_GlobalStoreMonitor::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_GlobalStoreMonitor::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 8 + os);
    delete[] s;
  }
};
mu_1_GlobalStoreMonitor::~mu_1_GlobalStoreMonitor()
{
}
/*** end array declaration ***/
mu_1_GlobalStoreMonitor mu_1_GlobalStoreMonitor_undefined_var;

class mu_1__type_4: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_4& val) { return mu__byte::operator=((int) val); };
  mu_1__type_4 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_4 (void): mu__byte(0, 3, 3) {};
  mu_1__type_4 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_Address mu_adr;
  mu_1_MessageType mu_mtype;
  mu_1_Machines mu_src;
  mu_1_Machines mu_dst;
  mu_1_ClValue mu_cl;
  mu_1__type_4 mu_acksExpectedL1C1;
  mu_1_Message ( const char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_dst, b.mu_dst);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = CompareWeight(a.mu_acksExpectedL1C1, b.mu_acksExpectedL1C1);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_adr, b.mu_adr);
    if (w!=0) return w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_dst, b.mu_dst);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = Compare(a.mu_acksExpectedL1C1, b.mu_acksExpectedL1C1);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_adr.MultisetSort();
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_dst.MultisetSort();
    mu_cl.MultisetSort();
    mu_acksExpectedL1C1.MultisetSort();
  }
  void print_statistic()
  {
    mu_adr.print_statistic();
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_dst.print_statistic();
    mu_cl.print_statistic();
    mu_acksExpectedL1C1.print_statistic();
  }
  void clear() {
    mu_adr.clear();
    mu_mtype.clear();
    mu_src.clear();
    mu_dst.clear();
    mu_cl.clear();
    mu_acksExpectedL1C1.clear();
 };
  void undefine() {
    mu_adr.undefine();
    mu_mtype.undefine();
    mu_src.undefine();
    mu_dst.undefine();
    mu_cl.undefine();
    mu_acksExpectedL1C1.undefine();
 };
  void reset() {
    mu_adr.reset();
    mu_mtype.reset();
    mu_src.reset();
    mu_dst.reset();
    mu_cl.reset();
    mu_acksExpectedL1C1.reset();
 };
  void print() {
    mu_adr.print();
    mu_mtype.print();
    mu_src.print();
    mu_dst.print();
    mu_cl.print();
    mu_acksExpectedL1C1.print();
  };
  void print_diff(state *prevstate) {
    mu_adr.print_diff(prevstate);
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_dst.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
    mu_acksExpectedL1C1.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_adr.to_state(thestate);
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_dst.to_state(thestate);
    mu_cl.to_state(thestate);
    mu_acksExpectedL1C1.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_adr.value(from.mu_adr.value());
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_dst.value(from.mu_dst.value());
    mu_cl.value(from.mu_cl.value());
    mu_acksExpectedL1C1.value(from.mu_acksExpectedL1C1.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_adr.set_self_2(name, ".adr", os + 0 ); else mu_adr.set_self_2(NULL, NULL, 0);
  if (name) mu_mtype.set_self_2(name, ".mtype", os + 8 ); else mu_mtype.set_self_2(NULL, NULL, 0);
  if (name) mu_src.set_self_2(name, ".src", os + 16 ); else mu_src.set_self_2(NULL, NULL, 0);
  if (name) mu_dst.set_self_2(name, ".dst", os + 24 ); else mu_dst.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 32 ); else mu_cl.set_self_2(NULL, NULL, 0);
  if (name) mu_acksExpectedL1C1.set_self_2(name, ".acksExpectedL1C1", os + 40 ); else mu_acksExpectedL1C1.set_self_2(NULL, NULL, 0);
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu__subrange_27: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu__subrange_27& val) { return mu__byte::operator=((int) val); };
  mu__subrange_27 (const char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu__subrange_27 (void): mu__byte(0, 2, 2) {};
  mu__subrange_27 (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu__subrange_27 mu__subrange_27_undefined_var;

class mu_1__type_5
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_5 (const char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 48 + os);
    delete[] s;
  }
};
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

class mu_1_NET_Ordered
{
 public:
  mu_1__type_5 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_NET_Ordered (const char *n, int os) { set_self(n, os); };
  mu_1_NET_Ordered ( void ) {};
  virtual ~mu_1_NET_Ordered ();
  mu_1__type_5& operator[] (int index) /* const */
  {
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - (36) ];
    if ( ( index >= 39 ) && ( index <= 39 ) )
      return array[ index - (36) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_NET_Ordered& operator= (const mu_1_NET_Ordered& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_NET_Ordered& a, mu_1_NET_Ordered& b)
  {
    return 0;
  }
friend int Compare(mu_1_NET_Ordered& a, mu_1_NET_Ordered& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_NET_Ordered::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_NET_Ordered::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_NET_Ordered::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directoryL1C1", i * 144 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_NET_Ordered::~mu_1_NET_Ordered()
{
}
/*** end array declaration ***/
mu_1_NET_Ordered mu_1_NET_Ordered_undefined_var;

class mu_1__type_6: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_6& val) { return mu__byte::operator=((int) val); };
  mu_1__type_6 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_6 (void): mu__byte(0, 3, 3) {};
  mu_1__type_6 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_6 mu_1__type_6_undefined_var;

class mu_1_NET_Ordered_cnt
{
 public:
  mu_1__type_6 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_NET_Ordered_cnt (const char *n, int os) { set_self(n, os); };
  mu_1_NET_Ordered_cnt ( void ) {};
  virtual ~mu_1_NET_Ordered_cnt ();
  mu_1__type_6& operator[] (int index) /* const */
  {
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - (36) ];
    if ( ( index >= 39 ) && ( index <= 39 ) )
      return array[ index - (36) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_NET_Ordered_cnt& operator= (const mu_1_NET_Ordered_cnt& from)
  {
    for (int i = 0; i < 4; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_NET_Ordered_cnt& a, mu_1_NET_Ordered_cnt& b)
  {
    return 0;
  }
friend int Compare(mu_1_NET_Ordered_cnt& a, mu_1_NET_Ordered_cnt& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_NET_Ordered_cnt::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_NET_Ordered_cnt::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_NET_Ordered_cnt::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directoryL1C1", i * 8 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_NET_Ordered_cnt::~mu_1_NET_Ordered_cnt()
{
}
/*** end array declaration ***/
mu_1_NET_Ordered_cnt mu_1_NET_Ordered_cnt_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_7_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_7_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_7_id () : mu__byte(0,2,0) {};
  mu_1__type_7_id (int val) : mu__byte(0,2,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_7
{
 public:
  mu_1_Message array[ 3 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 3 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_7 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_7 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_7 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 2) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_7& operator= (const mu_1__type_7& from)
  {
    for (int i = 0; i < 3; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_7& a, mu_1__type_7& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_7& a, mu_1__type_7& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_7_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 3; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 3; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 3) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 3; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_7_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 3; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 3; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 3; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1__type_7::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_7::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_7::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 3; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 48 + os); else array[i].set_self(NULL, 0);
  k = os + i * 48;
  for(i = 0; i < 3; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_7::~mu_1__type_7()
{
}
/*** end multiset declaration ***/
mu_1__type_7 mu_1__type_7_undefined_var;

class mu_1_NET_Unordered
{
 public:
  mu_1__type_7 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_NET_Unordered (const char *n, int os) { set_self(n, os); };
  mu_1_NET_Unordered ( void ) {};
  virtual ~mu_1_NET_Unordered ();
  mu_1__type_7& operator[] (int index) /* const */
  {
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - (36) ];
    if ( ( index >= 39 ) && ( index <= 39 ) )
      return array[ index - (36) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1_NET_Unordered& operator= (const mu_1_NET_Unordered& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_NET_Unordered& a, mu_1_NET_Unordered& b)
  {
    return 0;
  }
friend int Compare(mu_1_NET_Unordered& a, mu_1_NET_Unordered& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_NET_Unordered::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_NET_Unordered::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_NET_Unordered::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 168 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 168 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 168 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"directoryL1C1", i * 168 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_NET_Unordered::~mu_1_NET_Unordered()
{
}
/*** end array declaration ***/
mu_1_NET_Unordered mu_1_NET_Unordered_undefined_var;

/*** begin multiset declaration ***/
class mu_1_v_directoryL1C1_cacheL1C1_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_v_directoryL1C1_cacheL1C1_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1_v_directoryL1C1_cacheL1C1_id () : mu__byte(0,2,0) {};
  mu_1_v_directoryL1C1_cacheL1C1_id (int val) : mu__byte(0,2,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1_v_directoryL1C1_cacheL1C1
{
 public:
  mu_1_Machines array[ 3 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 3 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_v_directoryL1C1_cacheL1C1 (const char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1_v_directoryL1C1_cacheL1C1 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1_v_directoryL1C1_cacheL1C1 ();
  mu_1_Machines& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 2) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1_v_directoryL1C1_cacheL1C1& operator= (const mu_1_v_directoryL1C1_cacheL1C1& from)
  {
    for (int i = 0; i < 3; i++)
    {
        array[i].value(from.array[i].value());
        valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1_v_directoryL1C1_cacheL1C1& a, mu_1_v_directoryL1C1_cacheL1C1& b)
  {
    return 0;
  }
friend int Compare(mu_1_v_directoryL1C1_cacheL1C1& a, mu_1_v_directoryL1C1_cacheL1C1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 3; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 3; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1_v_directoryL1C1_cacheL1C1_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 3; i++)
      if (valid[i].value())
	array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
	 << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 3; i++)
      {
	StateCopy(workingstate, prevstate);
	prevvalid = valid[i].value();
	StateCopy(workingstate, &temp);
	if (prevvalid && !valid[i].value())
	  array[i].print();
	if (!prevvalid && valid[i].value())
	  array[i].print();
	if (prevvalid && valid[i].value())
	  array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Machines &element)
  {
    update_size();
    if (current_size >= 3) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 3; i++)
      if (!valid[i].value())
	{
	  array[i] = element;
	  valid[i].value(TRUE);
	  break;
	}
    current_size++;
    return i;
  };
  void multisetremove(const mu_1_v_directoryL1C1_cacheL1C1_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Machines temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 3; i++)
      if (valid[i].value())
	{
	  if (j!=i)
	    array[j++] = array[i];
	  else
	    j++;
	}
    if (j != current_size) current_size = j;
    for (i = j; i < 3; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 3; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
	if (Compare(array[i],array[j])>0)
	  {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	  }
  }
};

  void mu_1_v_directoryL1C1_cacheL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_v_directoryL1C1_cacheL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_v_directoryL1C1_cacheL1C1::set_self( const char *n, int os)
{
  int i,k;
  name = (char *)n;
  for(i = 0; i < 3; i++)
    if (n) array[i].set_self(tsprintf("%s{%d}", n,i), i * 8 + os); else array[i].set_self(NULL, 0);
  k = os + i * 8;
  for(i = 0; i < 3; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1_v_directoryL1C1_cacheL1C1::~mu_1_v_directoryL1C1_cacheL1C1()
{
}
/*** end multiset declaration ***/
mu_1_v_directoryL1C1_cacheL1C1 mu_1_v_directoryL1C1_cacheL1C1_undefined_var;

class mu_1_cnt_v_directoryL1C1_cacheL1C1: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_cnt_v_directoryL1C1_cacheL1C1& val) { return mu__byte::operator=((int) val); };
  mu_1_cnt_v_directoryL1C1_cacheL1C1 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_cnt_v_directoryL1C1_cacheL1C1 (void): mu__byte(0, 3, 3) {};
  mu_1_cnt_v_directoryL1C1_cacheL1C1 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_cnt_v_directoryL1C1_cacheL1C1 mu_1_cnt_v_directoryL1C1_cacheL1C1_undefined_var;

class mu_1_ENTRY_directoryL1C1
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_s_directoryL1C1 mu_State;
  mu_1_ClValue mu_cl;
  mu_1_v_directoryL1C1_cacheL1C1 mu_cacheL1C1;
  mu_1_Machines mu_ownerL1C1;
  mu_1_ENTRY_directoryL1C1 ( const char *n, int os ) { set_self(n,os); };
  mu_1_ENTRY_directoryL1C1 ( void ) {};

  virtual ~mu_1_ENTRY_directoryL1C1(); 
friend int CompareWeight(mu_1_ENTRY_directoryL1C1& a, mu_1_ENTRY_directoryL1C1& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cacheL1C1, b.mu_cacheL1C1);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ownerL1C1, b.mu_ownerL1C1);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ENTRY_directoryL1C1& a, mu_1_ENTRY_directoryL1C1& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = Compare(a.mu_cacheL1C1, b.mu_cacheL1C1);
    if (w!=0) return w;
    w = Compare(a.mu_ownerL1C1, b.mu_ownerL1C1);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_State.MultisetSort();
    mu_cl.MultisetSort();
    mu_cacheL1C1.MultisetSort();
    mu_ownerL1C1.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_cl.print_statistic();
    mu_cacheL1C1.print_statistic();
    mu_ownerL1C1.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_cl.clear();
    mu_cacheL1C1.clear();
    mu_ownerL1C1.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_cl.undefine();
    mu_cacheL1C1.undefine();
    mu_ownerL1C1.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_cl.reset();
    mu_cacheL1C1.reset();
    mu_ownerL1C1.reset();
 };
  void print() {
    mu_State.print();
    mu_cl.print();
    mu_cacheL1C1.print();
    mu_ownerL1C1.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
    mu_cacheL1C1.print_diff(prevstate);
    mu_ownerL1C1.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_cl.to_state(thestate);
    mu_cacheL1C1.to_state(thestate);
    mu_ownerL1C1.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ENTRY_directoryL1C1& operator= (const mu_1_ENTRY_directoryL1C1& from) {
    mu_State.value(from.mu_State.value());
    mu_cl.value(from.mu_cl.value());
    mu_cacheL1C1 = from.mu_cacheL1C1;
    mu_ownerL1C1.value(from.mu_ownerL1C1.value());
    return *this;
  };
};

  void mu_1_ENTRY_directoryL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ENTRY_directoryL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ENTRY_directoryL1C1::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_State.set_self_2(name, ".State", os + 0 ); else mu_State.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 8 ); else mu_cl.set_self_2(NULL, NULL, 0);
  if (name) mu_cacheL1C1.set_self_2(name, ".cacheL1C1", os + 16 ); else mu_cacheL1C1.set_self_2(NULL, NULL, 0);
  if (name) mu_ownerL1C1.set_self_2(name, ".ownerL1C1", os + 64 ); else mu_ownerL1C1.set_self_2(NULL, NULL, 0);
}

mu_1_ENTRY_directoryL1C1::~mu_1_ENTRY_directoryL1C1()
{
}

/*** end record declaration ***/
mu_1_ENTRY_directoryL1C1 mu_1_ENTRY_directoryL1C1_undefined_var;

class mu_1__type_8
{
 public:
  mu_1_ENTRY_directoryL1C1 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_8 (const char *n, int os) { set_self(n, os); };
  mu_1__type_8 ( void ) {};
  virtual ~mu_1__type_8 ();
  mu_1_ENTRY_directoryL1C1& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_8& operator= (const mu_1__type_8& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_8& a, mu_1__type_8& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_8::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_8::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_8::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 72 + os);
    delete[] s;
  }
};
mu_1__type_8::~mu_1__type_8()
{
}
/*** end array declaration ***/
mu_1__type_8 mu_1__type_8_undefined_var;

class mu_1_MACH_directoryL1C1
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_8 mu_cb;
  mu_1_MACH_directoryL1C1 ( const char *n, int os ) { set_self(n,os); };
  mu_1_MACH_directoryL1C1 ( void ) {};

  virtual ~mu_1_MACH_directoryL1C1(); 
friend int CompareWeight(mu_1_MACH_directoryL1C1& a, mu_1_MACH_directoryL1C1& b)
  {
    int w;
    w = CompareWeight(a.mu_cb, b.mu_cb);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_MACH_directoryL1C1& a, mu_1_MACH_directoryL1C1& b)
  {
    int w;
    w = Compare(a.mu_cb, b.mu_cb);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_cb.MultisetSort();
  }
  void print_statistic()
  {
    mu_cb.print_statistic();
  }
  void clear() {
    mu_cb.clear();
 };
  void undefine() {
    mu_cb.undefine();
 };
  void reset() {
    mu_cb.reset();
 };
  void print() {
    mu_cb.print();
  };
  void print_diff(state *prevstate) {
    mu_cb.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_cb.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_MACH_directoryL1C1& operator= (const mu_1_MACH_directoryL1C1& from) {
    mu_cb = from.mu_cb;
    return *this;
  };
};

  void mu_1_MACH_directoryL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_MACH_directoryL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_MACH_directoryL1C1::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_cb.set_self_2(name, ".cb", os + 0 ); else mu_cb.set_self_2(NULL, NULL, 0);
}

mu_1_MACH_directoryL1C1::~mu_1_MACH_directoryL1C1()
{
}

/*** end record declaration ***/
mu_1_MACH_directoryL1C1 mu_1_MACH_directoryL1C1_undefined_var;

class mu_1_OBJ_directoryL1C1
{
 public:
  mu_1_MACH_directoryL1C1 array[ 1 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_directoryL1C1 (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_directoryL1C1 ( void ) {};
  virtual ~mu_1_OBJ_directoryL1C1 ();
  mu_1_MACH_directoryL1C1& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 39 ) && ( index <= 39 ) )
      return array[ index - 39 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 39 ];
#endif
  };
  mu_1_OBJ_directoryL1C1& operator= (const mu_1_OBJ_directoryL1C1& from)
  {
      array[0] = from.array[0];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_directoryL1C1& a, mu_1_OBJ_directoryL1C1& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_OBJ_directoryL1C1& a, mu_1_OBJ_directoryL1C1& b)
  {
    int w;
    for (int i=0; i<1; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<1; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<1; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 1; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 1; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 1; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 1; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 1; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 1; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_directoryL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_directoryL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
  void mu_1_OBJ_directoryL1C1::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"directoryL1C1", i * 216 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
  }
mu_1_OBJ_directoryL1C1::~mu_1_OBJ_directoryL1C1()
{
}
/*** end array declaration ***/
mu_1_OBJ_directoryL1C1 mu_1_OBJ_directoryL1C1_undefined_var;

class mu_1__type_9: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_9& val) { return mu__byte::operator=((int) val); };
  mu_1__type_9 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_9 (void): mu__byte(0, 3, 3) {};
  mu_1__type_9 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_9 mu_1__type_9_undefined_var;

class mu_1__type_10: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_10& val) { return mu__byte::operator=((int) val); };
  mu_1__type_10 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_10 (void): mu__byte(0, 3, 3) {};
  mu_1__type_10 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_10 mu_1__type_10_undefined_var;

class mu_1_ENTRY_cacheL1C1
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_s_cacheL1C1 mu_State;
  mu_1_ClValue mu_cl;
  mu_1__type_9 mu_acksReceivedL1C1;
  mu_1__type_10 mu_acksExpectedL1C1;
  mu_1_ENTRY_cacheL1C1 ( const char *n, int os ) { set_self(n,os); };
  mu_1_ENTRY_cacheL1C1 ( void ) {};

  virtual ~mu_1_ENTRY_cacheL1C1(); 
friend int CompareWeight(mu_1_ENTRY_cacheL1C1& a, mu_1_ENTRY_cacheL1C1& b)
  {
    int w;
    w = CompareWeight(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = CompareWeight(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = CompareWeight(a.mu_acksReceivedL1C1, b.mu_acksReceivedL1C1);
    if (w!=0) return w;
    w = CompareWeight(a.mu_acksExpectedL1C1, b.mu_acksExpectedL1C1);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_ENTRY_cacheL1C1& a, mu_1_ENTRY_cacheL1C1& b)
  {
    int w;
    w = Compare(a.mu_State, b.mu_State);
    if (w!=0) return w;
    w = Compare(a.mu_cl, b.mu_cl);
    if (w!=0) return w;
    w = Compare(a.mu_acksReceivedL1C1, b.mu_acksReceivedL1C1);
    if (w!=0) return w;
    w = Compare(a.mu_acksExpectedL1C1, b.mu_acksExpectedL1C1);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_State.MultisetSort();
    mu_cl.MultisetSort();
    mu_acksReceivedL1C1.MultisetSort();
    mu_acksExpectedL1C1.MultisetSort();
  }
  void print_statistic()
  {
    mu_State.print_statistic();
    mu_cl.print_statistic();
    mu_acksReceivedL1C1.print_statistic();
    mu_acksExpectedL1C1.print_statistic();
  }
  void clear() {
    mu_State.clear();
    mu_cl.clear();
    mu_acksReceivedL1C1.clear();
    mu_acksExpectedL1C1.clear();
 };
  void undefine() {
    mu_State.undefine();
    mu_cl.undefine();
    mu_acksReceivedL1C1.undefine();
    mu_acksExpectedL1C1.undefine();
 };
  void reset() {
    mu_State.reset();
    mu_cl.reset();
    mu_acksReceivedL1C1.reset();
    mu_acksExpectedL1C1.reset();
 };
  void print() {
    mu_State.print();
    mu_cl.print();
    mu_acksReceivedL1C1.print();
    mu_acksExpectedL1C1.print();
  };
  void print_diff(state *prevstate) {
    mu_State.print_diff(prevstate);
    mu_cl.print_diff(prevstate);
    mu_acksReceivedL1C1.print_diff(prevstate);
    mu_acksExpectedL1C1.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_State.to_state(thestate);
    mu_cl.to_state(thestate);
    mu_acksReceivedL1C1.to_state(thestate);
    mu_acksExpectedL1C1.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_ENTRY_cacheL1C1& operator= (const mu_1_ENTRY_cacheL1C1& from) {
    mu_State.value(from.mu_State.value());
    mu_cl.value(from.mu_cl.value());
    mu_acksReceivedL1C1.value(from.mu_acksReceivedL1C1.value());
    mu_acksExpectedL1C1.value(from.mu_acksExpectedL1C1.value());
    return *this;
  };
};

  void mu_1_ENTRY_cacheL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_ENTRY_cacheL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_ENTRY_cacheL1C1::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_State.set_self_2(name, ".State", os + 0 ); else mu_State.set_self_2(NULL, NULL, 0);
  if (name) mu_cl.set_self_2(name, ".cl", os + 8 ); else mu_cl.set_self_2(NULL, NULL, 0);
  if (name) mu_acksReceivedL1C1.set_self_2(name, ".acksReceivedL1C1", os + 16 ); else mu_acksReceivedL1C1.set_self_2(NULL, NULL, 0);
  if (name) mu_acksExpectedL1C1.set_self_2(name, ".acksExpectedL1C1", os + 24 ); else mu_acksExpectedL1C1.set_self_2(NULL, NULL, 0);
}

mu_1_ENTRY_cacheL1C1::~mu_1_ENTRY_cacheL1C1()
{
}

/*** end record declaration ***/
mu_1_ENTRY_cacheL1C1 mu_1_ENTRY_cacheL1C1_undefined_var;

class mu_1__type_11
{
 public:
  mu_1_ENTRY_cacheL1C1 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1__type_11 (const char *n, int os) { set_self(n, os); };
  mu_1__type_11 ( void ) {};
  virtual ~mu_1__type_11 ();
  mu_1_ENTRY_cacheL1C1& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_11& operator= (const mu_1__type_11& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_11& a, mu_1__type_11& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_11& a, mu_1__type_11& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_11::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_11::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_11::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 32 + os);
    delete[] s;
  }
};
mu_1__type_11::~mu_1__type_11()
{
}
/*** end array declaration ***/
mu_1__type_11 mu_1__type_11_undefined_var;

class mu_1_MACH_cacheL1C1
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1__type_11 mu_cb;
  mu_1_MACH_cacheL1C1 ( const char *n, int os ) { set_self(n,os); };
  mu_1_MACH_cacheL1C1 ( void ) {};

  virtual ~mu_1_MACH_cacheL1C1(); 
friend int CompareWeight(mu_1_MACH_cacheL1C1& a, mu_1_MACH_cacheL1C1& b)
  {
    int w;
    w = CompareWeight(a.mu_cb, b.mu_cb);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_MACH_cacheL1C1& a, mu_1_MACH_cacheL1C1& b)
  {
    int w;
    w = Compare(a.mu_cb, b.mu_cb);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_cb.MultisetSort();
  }
  void print_statistic()
  {
    mu_cb.print_statistic();
  }
  void clear() {
    mu_cb.clear();
 };
  void undefine() {
    mu_cb.undefine();
 };
  void reset() {
    mu_cb.reset();
 };
  void print() {
    mu_cb.print();
  };
  void print_diff(state *prevstate) {
    mu_cb.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_cb.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_MACH_cacheL1C1& operator= (const mu_1_MACH_cacheL1C1& from) {
    mu_cb = from.mu_cb;
    return *this;
  };
};

  void mu_1_MACH_cacheL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_MACH_cacheL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_MACH_cacheL1C1::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_cb.set_self_2(name, ".cb", os + 0 ); else mu_cb.set_self_2(NULL, NULL, 0);
}

mu_1_MACH_cacheL1C1::~mu_1_MACH_cacheL1C1()
{
}

/*** end record declaration ***/
mu_1_MACH_cacheL1C1 mu_1_MACH_cacheL1C1_undefined_var;

class mu_1_OBJ_cacheL1C1
{
 public:
  mu_1_MACH_cacheL1C1 array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_OBJ_cacheL1C1 (const char *n, int os) { set_self(n, os); };
  mu_1_OBJ_cacheL1C1 ( void ) {};
  virtual ~mu_1_OBJ_cacheL1C1 ();
  mu_1_MACH_cacheL1C1& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 36 ) && ( index <= 38 ) )
      return array[ index - 36 ];
    else
      {
	if (index==UNDEFVAL) 
	  Error.Error("Indexing to %s using an undefined value.", name);
	else
	  Error.Error("Funny index value %d for %s: OBJSET_cacheL1C1 is internally represented from 36 to 38.\nInternal Error in Type checking.",index, name);
	return array[0];
      }
#else
    return array[ index - 36 ];
#endif
  };
  mu_1_OBJ_cacheL1C1& operator= (const mu_1_OBJ_cacheL1C1& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1_OBJ_cacheL1C1& a, mu_1_OBJ_cacheL1C1& b)
  {
    return 0;
  }
friend int Compare(mu_1_OBJ_cacheL1C1& a, mu_1_OBJ_cacheL1C1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_OBJ_cacheL1C1::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_OBJ_cacheL1C1::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_OBJ_cacheL1C1::set_self( const char *n, int os)
  {
    int i=0;
    name = (char *)n;

if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_1", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_2", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
if (n) array[i].set_self_ar(n,"OBJSET_cacheL1C1_3", i * 96 + os); else array[i].set_self_ar(NULL, NULL, 0); i++;
}
mu_1_OBJ_cacheL1C1::~mu_1_OBJ_cacheL1C1()
{
}
/*** end array declaration ***/
mu_1_OBJ_cacheL1C1 mu_1_OBJ_cacheL1C1_undefined_var;

class mu_1__type_12: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_12& val) { return mu__byte::operator=((int) val); };
  mu_1__type_12 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_12 (void): mu__byte(0, 3, 3) {};
  mu_1__type_12 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_12 mu_1__type_12_undefined_var;

class mu_1__type_13: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_13& val) { return mu__byte::operator=((int) val); };
  mu_1__type_13 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_13 (void): mu__byte(0, 3, 3) {};
  mu_1__type_13 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_13 mu_1__type_13_undefined_var;

class mu_1__type_14: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_14& val) { return mu__byte::operator=((int) val); };
  mu_1__type_14 (const char *name, int os): mu__byte(0, 6, 3, name, os) {};
  mu_1__type_14 (void): mu__byte(0, 6, 3) {};
  mu_1__type_14 (int val): mu__byte(0, 6, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_14 mu_1__type_14_undefined_var;

class mu_1__type_15: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1__type_15& val) { return mu__byte::operator=((int) val); };
  mu_1__type_15 (const char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1__type_15 (void): mu__byte(0, 3, 3) {};
  mu_1__type_15 (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1__type_15 mu_1__type_15_undefined_var;

const int mu_ENABLE_QS = 0;
const int mu_VAL_COUNT = 2;
const int mu_ADR_COUNT = 2;
const int mu_O_NET_MAX = 3;
const int mu_U_NET_MAX = 3;
const int mu_NrCachesL1C1 = 3;
const int mu_none = 1;
const int mu_load = 2;
const int mu_acquire = 3;
const int mu_store = 4;
const int mu_release = 5;
const int mu_fence = 6;
const int mu_GetSL1C1 = 7;
const int mu_GetML1C1 = 8;
const int mu_PutSL1C1 = 9;
const int mu_Inv_AckL1C1 = 10;
const int mu_GetM_Ack_DL1C1 = 11;
const int mu_GetS_AckL1C1 = 12;
const int mu_WBL1C1 = 13;
const int mu_PutML1C1 = 14;
const int mu_GetM_Ack_ADL1C1 = 15;
const int mu_InvL1C1 = 16;
const int mu_Put_AckL1C1 = 17;
const int mu_Fwd_GetSL1C1 = 18;
const int mu_Fwd_GetML1C1 = 19;
const int mu_cacheL1C1_S_store_GetM_Ack_AD = 20;
const int mu_cacheL1C1_S_store = 21;
const int mu_cacheL1C1_S_evict = 22;
const int mu_cacheL1C1_S = 23;
const int mu_cacheL1C1_M_evict = 24;
const int mu_cacheL1C1_M = 25;
const int mu_cacheL1C1_I_x_S_evict = 26;
const int mu_cacheL1C1_I_x_M_evict = 27;
const int mu_cacheL1C1_I_store_GetM_Ack_AD = 28;
const int mu_cacheL1C1_I_store = 29;
const int mu_cacheL1C1_I_load = 30;
const int mu_cacheL1C1_I = 31;
const int mu_directoryL1C1_S = 32;
const int mu_directoryL1C1_M_GetS = 33;
const int mu_directoryL1C1_M = 34;
const int mu_directoryL1C1_I = 35;
const int mu_OBJSET_cacheL1C1_1 = 36;
const int mu_OBJSET_cacheL1C1_2 = 37;
const int mu_OBJSET_cacheL1C1_3 = 38;
const int mu_directoryL1C1 = 39;
/*** Variable declaration ***/
mu_1_NET_Ordered mu_fwd("fwd",0);

/*** Variable declaration ***/
mu_1_NET_Ordered_cnt mu_cnt_fwd("cnt_fwd",576);

/*** Variable declaration ***/
mu_1_NET_Ordered mu_resp("resp",608);

/*** Variable declaration ***/
mu_1_NET_Ordered_cnt mu_cnt_resp("cnt_resp",1184);

/*** Variable declaration ***/
mu_1_NET_Ordered mu_req("req",1216);

/*** Variable declaration ***/
mu_1_NET_Ordered_cnt mu_cnt_req("cnt_req",1792);

/*** Variable declaration ***/
mu_1_PermMonitor mu_g_perm("g_perm",1824);

/*** Variable declaration ***/
mu_1_GlobalStoreMonitor mu_g_monitor_store("g_monitor_store",2400);

/*** Variable declaration ***/
mu_1_OBJ_directoryL1C1 mu_i_directoryL1C1("i_directoryL1C1",2424);

/*** Variable declaration ***/
mu_1_OBJ_cacheL1C1 mu_i_cacheL1C1("i_cacheL1C1",2640);

/*** Variable declaration ***/
mu_1_thread mu_i_thread1("i_thread1",2928);

/*** Variable declaration ***/
mu_1_thread mu_i_thread2("i_thread2",3024);

/*** Variable declaration ***/
mu_1_thread mu_i_thread3("i_thread3",3120);

/*** Variable declaration ***/
mu_1_threadlist mu_i_threadlist("i_threadlist",3216);

/*** Variable declaration ***/
mu_1_threadIndexes mu_i_threadIndexes("i_threadIndexes",3504);

/*** Variable declaration ***/
mu_1__type_12 mu_initializer("initializer",3624);

/*** Variable declaration ***/
mu_1__type_13 mu_loadedZeroCounter("loadedZeroCounter",3632);

/*** Variable declaration ***/
mu_1__type_14 mu_instructionsExecuted("instructionsExecuted",3640);

void mu_Reset_directoryL1C1()
{
{
for(int mu_i = 39; mu_i <= 39; mu_i++) {
{
for(int mu_a = 0; mu_a <= 2; mu_a++) {
mu_i_directoryL1C1[mu_i].mu_cb[mu_a].mu_State = mu_directoryL1C1_I;
mu_i_directoryL1C1[mu_i].mu_cb[mu_a].mu_cl = 0;
};
};
};
};
};
/*** end procedure declaration ***/

void mu_Reset_cacheL1C1()
{
{
for(int mu_i = 36; mu_i <= 38; mu_i++) {
{
for(int mu_a = 0; mu_a <= 2; mu_a++) {
mu_i_cacheL1C1[mu_i].mu_cb[mu_a].mu_State = mu_cacheL1C1_I;
mu_i_cacheL1C1[mu_i].mu_cb[mu_a].mu_cl = 0;
mu_i_cacheL1C1[mu_i].mu_cb[mu_a].mu_acksReceivedL1C1 = 0;
mu_i_cacheL1C1[mu_i].mu_cb[mu_a].mu_acksExpectedL1C1 = 0;
};
};
};
};
};
/*** end procedure declaration ***/

void mu_Clear_perm(const mu_1_Address& mu_adr, const mu_1_Machines& mu_m)
{
{
  mu_1_acc_type_obj& mu_l_perm_set = mu_g_perm[mu_m][mu_adr];
mu_l_perm_set.undefine();
}
};
/*** end procedure declaration ***/

void mu_Set_perm(const mu_1_PermissionType& mu_acc_type, const mu_1_Address& mu_adr, const mu_1_Machines& mu_m)
{
{
  mu_1_acc_type_obj& mu_l_perm_set = mu_g_perm[mu_m][mu_adr];
mu_l_perm_set.multisetadd(mu_acc_type);
}
};
/*** end procedure declaration ***/

void mu_Reset_perm()
{
{
for(int mu_m = 36; mu_m <= 39; mu_m++)
  if (( ( mu_m >= 39 ) && ( mu_m <= 39 ) )|| ( ( mu_m >= 36 ) && ( mu_m <= 38 ) )) {
{
for(int mu_adr = 0; mu_adr <= 2; mu_adr++) {
mu_Clear_perm ( mu_adr, mu_m );
};
};
};
};
};
/*** end procedure declaration ***/

void mu_Execute_store_monitor(const mu_1_ClValue& mu_cb, const mu_1_Address& mu_adr)
{
{
  mu_1_ClValue& mu_cbe = mu_g_monitor_store[mu_adr];
if ( (mu_cbe) == (mu_cb) )
{
if ( (mu_cbe) == (mu_VAL_COUNT) )
{
mu_cbe = 0;
}
else
{
mu_cbe = (mu_cbe) + (1);
}
}
else
{
Error.Error("Error: Write linearization failed");
}
}
};
/*** end procedure declaration ***/

void mu_Reset_global_monitor()
{
{
for(int mu_adr = 0; mu_adr <= 2; mu_adr++) {
mu_g_monitor_store[mu_adr] = 0;
};
};
};
/*** end procedure declaration ***/

void mu_AddElement_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv, const mu_1_Machines& mu_n)
{
/*** begin multisetcount 0 declaration ***/
  int mu__intexpr16 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( (mu_sv[mu_i]) == (mu_n) ) mu__intexpr16++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( (mu__intexpr16) == (0) )
{
mu_sv.multisetadd(mu_n);
}
};
/*** end procedure declaration ***/

void mu_RemoveElement_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv, const mu_1_Machines& mu_n)
{
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr17 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( (mu_sv[mu_i]) == (mu_n) ) mu__intexpr17++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
if ( (mu__intexpr17) == (1) )
{
/*** end multisetremove 0 declaration ***/
  mu_1_v_directoryL1C1_cacheL1C1_id mu__idexpr18;
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( (mu_sv[mu_i]) == (mu_n) ) { mu__idexpr18 = mu_i; mu_sv.multisetremove(mu__idexpr18); };
	}
      if (mu_i == 3-1) break;
    }
/*** end multisetremove 0 declaration ***/
}
};
/*** end procedure declaration ***/

void mu_ClearVector_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv)
{
/*** end multisetremove 1 declaration ***/
  mu_1_v_directoryL1C1_cacheL1C1_id mu__idexpr19;
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( mu_true ) { mu__idexpr19 = mu_i; mu_sv.multisetremove(mu__idexpr19); };
	}
      if (mu_i == 3-1) break;
    }
/*** end multisetremove 1 declaration ***/
};
/*** end procedure declaration ***/

mu_0_boolean mu_IsElement_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv,const mu_1_Machines& mu_n)
{
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr20 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( (mu_sv[mu_i]) == (mu_n) ) mu__intexpr20++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
if ( (mu__intexpr20) == (1) )
{
return mu_true;
}
else
{
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr21 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( (mu_sv[mu_i]) == (mu_n) ) mu__intexpr21++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
if ( (mu__intexpr21) == (0) )
{
return mu_false;
}
else
{
Error.Error("Error: Multiple Entries of Sharer in SV multiset");
}
}
return mu_false;
	Error.Error("The end of function IsElement_directoryL1C1_cacheL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_HasElement_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv,const mu_1_Machines& mu_n)
{
/*** begin multisetcount 4 declaration ***/
  int mu__intexpr22 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr22++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 4 declaration ***/
if ( (mu__intexpr22) == (0) )
{
return mu_false;
}
return mu_true;
	Error.Error("The end of function HasElement_directoryL1C1_cacheL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_1_cnt_v_directoryL1C1_cacheL1C1 mu_VectorCount_directoryL1C1_cacheL1C1(mu_1_v_directoryL1C1_cacheL1C1& mu_sv)
{
/*** begin multisetcount 5 declaration ***/
  int mu__intexpr23 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_sv.valid[(int)mu_i].value())
	{
	  if ( mu_true ) mu__intexpr23++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 5 declaration ***/
return mu__intexpr23;
	Error.Error("The end of function VectorCount_directoryL1C1_cacheL1C1 reached without returning values.");
};
/*** end function declaration ***/

void mu_Send_fwd(mu_1_Message& mu_msg, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_fwd[mu_msg.mu_dst]) < (mu_O_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_fwd[mu_msg.mu_dst][mu_cnt_fwd[mu_msg.mu_dst]] = mu_msg;
mu_cnt_fwd[mu_msg.mu_dst] = (mu_cnt_fwd[mu_msg.mu_dst]) + (1);
};
/*** end procedure declaration ***/

void mu_Pop_fwd(const mu_1_Machines& mu_dst, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_fwd[mu_dst]) > (0)) ) Error.Error("Assertion failed: Trying to advance empty Q");
{
int mu__ub24 = (mu_cnt_fwd[mu_dst]) - (1);
for (int mu_i = 0; mu_i <= mu__ub24; mu_i += 1) {
if ( (mu_i) < ((mu_cnt_fwd[mu_dst]) - (1)) )
{
mu_fwd[mu_dst][mu_i] = mu_fwd[mu_dst][(mu_i) + (1)];
}
else
{
mu_fwd[mu_dst][mu_i].undefine();
}
};
};
mu_cnt_fwd[mu_dst] = (mu_cnt_fwd[mu_dst]) - (1);
};
/*** end procedure declaration ***/

void mu_Send_resp(mu_1_Message& mu_msg, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_resp[mu_msg.mu_dst]) < (mu_O_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_resp[mu_msg.mu_dst][mu_cnt_resp[mu_msg.mu_dst]] = mu_msg;
mu_cnt_resp[mu_msg.mu_dst] = (mu_cnt_resp[mu_msg.mu_dst]) + (1);
};
/*** end procedure declaration ***/

void mu_Pop_resp(const mu_1_Machines& mu_dst, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_resp[mu_dst]) > (0)) ) Error.Error("Assertion failed: Trying to advance empty Q");
{
int mu__ub25 = (mu_cnt_resp[mu_dst]) - (1);
for (int mu_i = 0; mu_i <= mu__ub25; mu_i += 1) {
if ( (mu_i) < ((mu_cnt_resp[mu_dst]) - (1)) )
{
mu_resp[mu_dst][mu_i] = mu_resp[mu_dst][(mu_i) + (1)];
}
else
{
mu_resp[mu_dst][mu_i].undefine();
}
};
};
mu_cnt_resp[mu_dst] = (mu_cnt_resp[mu_dst]) - (1);
};
/*** end procedure declaration ***/

void mu_Send_req(mu_1_Message& mu_msg, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_req[mu_msg.mu_dst]) < (mu_O_NET_MAX)) ) Error.Error("Assertion failed: Too many messages");
mu_req[mu_msg.mu_dst][mu_cnt_req[mu_msg.mu_dst]] = mu_msg;
mu_cnt_req[mu_msg.mu_dst] = (mu_cnt_req[mu_msg.mu_dst]) + (1);
};
/*** end procedure declaration ***/

void mu_Pop_req(const mu_1_Machines& mu_dst, const mu_1_Machines& mu_src)
{
if ( !((mu_cnt_req[mu_dst]) > (0)) ) Error.Error("Assertion failed: Trying to advance empty Q");
{
int mu__ub26 = (mu_cnt_req[mu_dst]) - (1);
for (int mu_i = 0; mu_i <= mu__ub26; mu_i += 1) {
if ( (mu_i) < ((mu_cnt_req[mu_dst]) - (1)) )
{
mu_req[mu_dst][mu_i] = mu_req[mu_dst][(mu_i) + (1)];
}
else
{
mu_req[mu_dst][mu_i].undefine();
}
};
};
mu_cnt_req[mu_dst] = (mu_cnt_req[mu_dst]) - (1);
};
/*** end procedure declaration ***/

void mu_Multicast_fwd_C1(mu_1_Message& mu_msg, mu_1_v_directoryL1C1_cacheL1C1& mu_dst_vect, const mu_1_Machines& mu_src)
{
{
for(int mu_n = 36; mu_n <= 39; mu_n++)
  if (( ( mu_n >= 39 ) && ( mu_n <= 39 ) )|| ( ( mu_n >= 36 ) && ( mu_n <= 38 ) )) {
if ( (mu_n) != (mu_msg.mu_src) )
{
/*** begin multisetcount 6 declaration ***/
  int mu__intexpr27 = 0;
  {
  mu_1_v_directoryL1C1_cacheL1C1_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_dst_vect.valid[(int)mu_i].value())
	{
	  if ( (mu_dst_vect[mu_i]) == (mu_n) ) mu__intexpr27++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 6 declaration ***/
if ( (mu__intexpr27) == (1) )
{
mu_msg.mu_dst = mu_n;
mu_Send_fwd ( mu_msg, mu_src );
}
}
};
};
};
/*** end procedure declaration ***/

mu_0_boolean mu_req_network_ready()
{
{
for(int mu_dst = 36; mu_dst <= 39; mu_dst++)
  if (( ( mu_dst >= 39 ) && ( mu_dst <= 39 ) )|| ( ( mu_dst >= 36 ) && ( mu_dst <= 38 ) )) {
{
for(int mu_src = 36; mu_src <= 39; mu_src++)
  if (( ( mu_src >= 39 ) && ( mu_src <= 39 ) )|| ( ( mu_src >= 36 ) && ( mu_src <= 38 ) )) {
if ( (mu_cnt_req[mu_dst]) >= (1) )
{
return mu_false;
}
};
};
};
};
return mu_true;
	Error.Error("The end of function req_network_ready reached without returning values.");
};
/*** end function declaration ***/

void mu_Reset_NET_()
{
mu_fwd.undefine();
{
for(int mu_dst = 36; mu_dst <= 39; mu_dst++)
  if (( ( mu_dst >= 39 ) && ( mu_dst <= 39 ) )|| ( ( mu_dst >= 36 ) && ( mu_dst <= 38 ) )) {
mu_cnt_fwd[mu_dst] = 0;
};
};
mu_req.undefine();
{
for(int mu_dst = 36; mu_dst <= 39; mu_dst++)
  if (( ( mu_dst >= 39 ) && ( mu_dst <= 39 ) )|| ( ( mu_dst >= 36 ) && ( mu_dst <= 38 ) )) {
mu_cnt_req[mu_dst] = 0;
};
};
mu_resp.undefine();
{
for(int mu_dst = 36; mu_dst <= 39; mu_dst++)
  if (( ( mu_dst >= 39 ) && ( mu_dst <= 39 ) )|| ( ( mu_dst >= 36 ) && ( mu_dst <= 38 ) )) {
mu_cnt_resp[mu_dst] = 0;
};
};
};
/*** end procedure declaration ***/

void mu_Reset_Threads()
{
mu_i_thread1[0].mu_itype = mu_store;
mu_i_thread1[0].mu_val = 1;
mu_i_thread1[0].mu_adr = 0;
mu_i_thread1[1].mu_itype = mu_load;
mu_i_thread1[1].mu_val = 0;
mu_i_thread1[1].mu_adr = 1;
mu_i_thread2[0].mu_itype = mu_store;
mu_i_thread2[0].mu_val = 1;
mu_i_thread2[0].mu_adr = 1;
mu_i_thread2[1].mu_itype = mu_load;
mu_i_thread2[1].mu_val = 0;
mu_i_thread2[1].mu_adr = 2;
mu_i_thread3[0].mu_itype = mu_store;
mu_i_thread3[0].mu_val = 1;
mu_i_thread3[0].mu_adr = 2;
mu_i_thread3[1].mu_itype = mu_load;
mu_i_thread3[1].mu_val = 0;
mu_i_thread3[1].mu_adr = 0;
mu_i_thread1[2].mu_adr = 0;
mu_i_thread2[2].mu_adr = 0;
mu_i_thread3[2].mu_adr = 0;
mu_initializer = 0;
mu_instructionsExecuted = 0;
mu_loadedZeroCounter = 0;
{
for(int mu_m = 36; mu_m <= 38; mu_m++) {
mu_i_threadIndexes[mu_m].mu_currentIndex = 0;
if ( (mu_initializer) == (0) )
{
mu_i_threadIndexes[mu_m].mu_maxIndex = 1;
mu_i_threadlist[mu_m] = mu_i_thread1;
mu_initializer = (mu_initializer) + (1);
}
else
{
if ( (mu_initializer) == (1) )
{
mu_i_threadIndexes[mu_m].mu_maxIndex = 1;
mu_i_threadlist[mu_m] = mu_i_thread2;
mu_initializer = (mu_initializer) + (1);
}
else
{
if ( (mu_initializer) == (2) )
{
mu_i_threadIndexes[mu_m].mu_maxIndex = 1;
mu_i_threadlist[mu_m] = mu_i_thread3;
mu_initializer = (mu_initializer) + (1);
}
else
{
if ( (mu_initializer) == (3) )
{
mu_i_threadIndexes[mu_m].mu_maxIndex = 1;
mu_i_threadIndexes[mu_m].mu_currentIndex = 2;
}
}
}
}
};
};
};
/*** end procedure declaration ***/

void mu_resetEverything()
{
if ( (mu_loadedZeroCounter) == (3) )
{
Error.Error("Error: Litmus test failed");
}
mu_Reset_perm (  );
mu_Reset_global_monitor (  );
mu_Reset_NET_ (  );
mu_Reset_directoryL1C1 (  );
mu_Reset_cacheL1C1 (  );
mu_Reset_Threads (  );
};
/*** end procedure declaration ***/

mu_1_Message mu_RequestL1C1(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
return mu_msg;
	Error.Error("The end of function RequestL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_AckL1C1(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
return mu_msg;
	Error.Error("The end of function AckL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_RespL1C1(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst,const mu_1_ClValue& mu_cl)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
if (mu_cl.isundefined())
  mu_msg.mu_cl.undefine();
else
  mu_msg.mu_cl = mu_cl;
return mu_msg;
	Error.Error("The end of function RespL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_1_Message mu_RespAckL1C1(const mu_1_Address& mu_adr,const mu_1_MessageType& mu_mtype,const mu_1_Machines& mu_src,const mu_1_Machines& mu_dst,const mu_1_ClValue& mu_cl,const mu_1__type_15& mu_acksExpectedL1C1)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

if (mu_adr.isundefined())
  mu_msg.mu_adr.undefine();
else
  mu_msg.mu_adr = mu_adr;
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_dst.isundefined())
  mu_msg.mu_dst.undefine();
else
  mu_msg.mu_dst = mu_dst;
if (mu_cl.isundefined())
  mu_msg.mu_cl.undefine();
else
  mu_msg.mu_cl = mu_cl;
if (mu_acksExpectedL1C1.isundefined())
  mu_msg.mu_acksExpectedL1C1.undefine();
else
  mu_msg.mu_acksExpectedL1C1 = mu_acksExpectedL1C1;
return mu_msg;
	Error.Error("The end of function RespAckL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_FSM_MSG_directoryL1C1(mu_1_Message& mu_inmsg,const mu_1_OBJSET_directoryL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  const int mu_adr = mu_inmsg.mu_adr;
{
  mu_1_ENTRY_directoryL1C1& mu_cbe = mu_i_directoryL1C1[mu_m].mu_cb[mu_adr];
switch ((int) mu_cbe.mu_State) {
case mu_directoryL1C1_I:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetML1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_GetM_Ack_DL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
if (mu_inmsg.mu_src.isundefined())
  mu_cbe.mu_ownerL1C1.undefine();
else
  mu_cbe.mu_ownerL1C1 = mu_inmsg.mu_src;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
break;
case mu_GetSL1C1:
mu_AddElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
mu_msg = mu_RespL1C1( mu_adr, mu_GetS_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_S;
return mu_true;
break;
case mu_PutML1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
if ( (mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src) )
{
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
if ( !((mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
break;
case mu_PutSL1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
mu_RemoveElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
if ( !((mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
if ( (mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
case mu_directoryL1C1_M:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetML1C1:
mu_msg = mu_RequestL1C1( mu_adr, mu_Fwd_GetML1C1, mu_inmsg.mu_src, mu_cbe.mu_ownerL1C1 );
mu_Send_fwd ( mu_msg, (int)mu_m );
if (mu_inmsg.mu_src.isundefined())
  mu_cbe.mu_ownerL1C1.undefine();
else
  mu_cbe.mu_ownerL1C1 = mu_inmsg.mu_src;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
break;
case mu_GetSL1C1:
mu_msg = mu_RequestL1C1( mu_adr, mu_Fwd_GetSL1C1, mu_inmsg.mu_src, mu_cbe.mu_ownerL1C1 );
mu_Send_fwd ( mu_msg, (int)mu_m );
mu_AddElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
mu_AddElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_cbe.mu_ownerL1C1 );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M_GetS;
return mu_true;
break;
case mu_PutML1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
if ( !((mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
}
if ( (mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src) )
{
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
break;
case mu_PutSL1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
if ( !((mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
}
if ( (mu_cbe.mu_ownerL1C1) == (mu_inmsg.mu_src) )
{
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
case mu_directoryL1C1_M_GetS:
switch ((int) mu_inmsg.mu_mtype) {
case mu_WBL1C1:
if ( !((mu_inmsg.mu_src) == (mu_cbe.mu_ownerL1C1)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M_GetS;
return mu_true;
}
if ( (mu_inmsg.mu_src) == (mu_cbe.mu_ownerL1C1) )
{
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_S;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
case mu_directoryL1C1_S:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetML1C1:
if ( mu_IsElement_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src ) )
{
mu_RemoveElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
if ( !((mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0)) )
{
mu_msg = mu_RespAckL1C1( mu_adr, mu_GetM_Ack_ADL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl, (int)mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 ) );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_msg = mu_AckL1C1( mu_adr, mu_InvL1C1, mu_inmsg.mu_src, mu_inmsg.mu_src );
mu_Multicast_fwd_C1 ( mu_msg, mu_cbe.mu_cacheL1C1, (int)mu_m );
if (mu_inmsg.mu_src.isundefined())
  mu_cbe.mu_ownerL1C1.undefine();
else
  mu_cbe.mu_ownerL1C1 = mu_inmsg.mu_src;
mu_ClearVector_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1 );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
}
if ( (mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0) )
{
mu_msg = mu_RespL1C1( mu_adr, mu_GetM_Ack_DL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
if (mu_inmsg.mu_src.isundefined())
  mu_cbe.mu_ownerL1C1.undefine();
else
  mu_cbe.mu_ownerL1C1 = mu_inmsg.mu_src;
mu_ClearVector_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1 );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
}
}
if ( !(mu_IsElement_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src )) )
{
mu_msg = mu_RespAckL1C1( mu_adr, mu_GetM_Ack_ADL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl, (int)mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 ) );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_msg = mu_AckL1C1( mu_adr, mu_InvL1C1, mu_inmsg.mu_src, mu_inmsg.mu_src );
mu_Multicast_fwd_C1 ( mu_msg, mu_cbe.mu_cacheL1C1, (int)mu_m );
if (mu_inmsg.mu_src.isundefined())
  mu_cbe.mu_ownerL1C1.undefine();
else
  mu_cbe.mu_ownerL1C1 = mu_inmsg.mu_src;
mu_ClearVector_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1 );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_M;
return mu_true;
}
break;
case mu_GetSL1C1:
mu_AddElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
mu_msg = mu_RespL1C1( mu_adr, mu_GetS_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_S;
return mu_true;
break;
case mu_PutML1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
mu_RemoveElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
if ( (mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
if ( !((mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_S;
return mu_true;
}
break;
case mu_PutSL1C1:
mu_msg = mu_AckL1C1( mu_adr, mu_Put_AckL1C1, (int)mu_m, mu_inmsg.mu_src );
mu_Send_fwd ( mu_msg, (int)mu_m );
mu_RemoveElement_directoryL1C1_cacheL1C1 ( mu_cbe.mu_cacheL1C1, mu_inmsg.mu_src );
if ( (mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_I;
return mu_true;
}
if ( !((mu_VectorCount_directoryL1C1_cacheL1C1( mu_cbe.mu_cacheL1C1 )) == (0)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_directoryL1C1_S;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
}
}
}
return mu_false;
	Error.Error("The end of function FSM_MSG_directoryL1C1 reached without returning values.");
};
/*** end function declaration ***/

mu_0_boolean mu_FSM_MSG_cacheL1C1(mu_1_Message& mu_inmsg,const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  const int mu_adr = mu_inmsg.mu_adr;
{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
switch ((int) mu_cbe.mu_State) {
case mu_cacheL1C1_I:
switch ((int) mu_inmsg.mu_mtype) {
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_I_load:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetS_AckL1C1:
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_I_store:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM_Ack_ADL1C1:
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
if (mu_inmsg.mu_acksExpectedL1C1.isundefined())
  mu_cbe.mu_acksExpectedL1C1.undefine();
else
  mu_cbe.mu_acksExpectedL1C1 = mu_inmsg.mu_acksExpectedL1C1;
if ( !((mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_store_GetM_Ack_AD;
return mu_true;
}
if ( (mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
}
break;
case mu_GetM_Ack_DL1C1:
if (mu_inmsg.mu_cl.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_inmsg.mu_cl;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
break;
case mu_Inv_AckL1C1:
mu_cbe.mu_acksReceivedL1C1 = (mu_cbe.mu_acksReceivedL1C1) + (1);
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_store;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_I_store_GetM_Ack_AD:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Inv_AckL1C1:
mu_cbe.mu_acksReceivedL1C1 = (mu_cbe.mu_acksReceivedL1C1) + (1);
if ( !((mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_store_GetM_Ack_AD;
return mu_true;
}
if ( (mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_I_x_M_evict:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Put_AckL1C1:
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_I_x_S_evict:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Put_AckL1C1:
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_M:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Fwd_GetML1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_GetM_Ack_DL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
case mu_Fwd_GetSL1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_GetS_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_msg = mu_RespL1C1( mu_adr, mu_WBL1C1, (int)mu_m, (int)mu_directoryL1C1, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_M_evict:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Fwd_GetML1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_GetM_Ack_DL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_x_M_evict;
return mu_true;
break;
case mu_Fwd_GetSL1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_GetS_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_msg = mu_RespL1C1( mu_adr, mu_WBL1C1, (int)mu_m, (int)mu_directoryL1C1, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_evict;
return mu_true;
break;
case mu_Put_AckL1C1:
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_S:
switch ((int) mu_inmsg.mu_mtype) {
case mu_InvL1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_Inv_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_S_evict:
switch ((int) mu_inmsg.mu_mtype) {
case mu_InvL1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_Inv_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_x_S_evict;
return mu_true;
break;
case mu_Put_AckL1C1:
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_S_store:
switch ((int) mu_inmsg.mu_mtype) {
case mu_GetM_Ack_ADL1C1:
if (mu_inmsg.mu_acksExpectedL1C1.isundefined())
  mu_cbe.mu_acksExpectedL1C1.undefine();
else
  mu_cbe.mu_acksExpectedL1C1 = mu_inmsg.mu_acksExpectedL1C1;
if ( !((mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_store_GetM_Ack_AD;
return mu_true;
}
if ( (mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
}
break;
case mu_GetM_Ack_DL1C1:
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
break;
case mu_InvL1C1:
mu_msg = mu_RespL1C1( mu_adr, mu_Inv_AckL1C1, (int)mu_m, mu_inmsg.mu_src, mu_cbe.mu_cl );
mu_Send_resp ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_store;
return mu_true;
break;
case mu_Inv_AckL1C1:
mu_cbe.mu_acksReceivedL1C1 = (mu_cbe.mu_acksReceivedL1C1) + (1);
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_store;
return mu_true;
break;
default:
return mu_false;
break;
}
break;
case mu_cacheL1C1_S_store_GetM_Ack_AD:
switch ((int) mu_inmsg.mu_mtype) {
case mu_Inv_AckL1C1:
mu_cbe.mu_acksReceivedL1C1 = (mu_cbe.mu_acksReceivedL1C1) + (1);
if ( !((mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1)) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_store_GetM_Ack_AD;
return mu_true;
}
if ( (mu_cbe.mu_acksExpectedL1C1) == (mu_cbe.mu_acksReceivedL1C1) )
{
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
return mu_true;
}
break;
default:
return mu_false;
break;
}
break;
}
}
}
return mu_false;
	Error.Error("The end of function FSM_MSG_cacheL1C1 reached without returning values.");
};
/*** end function declaration ***/

void mu_FSM_Access_cacheL1C1_I_load(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_msg = mu_RequestL1C1( mu_adr, mu_GetSL1C1, (int)mu_m, (int)mu_directoryL1C1 );
mu_Send_req ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_load;
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_I_store(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m, const mu_1_ClValue& mu_v)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_msg = mu_RequestL1C1( mu_adr, mu_GetML1C1, (int)mu_m, (int)mu_directoryL1C1 );
mu_Send_req ( mu_msg, (int)mu_m );
mu_cbe.mu_acksReceivedL1C1 = 0;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_I_store;
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_M_evict(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_msg = mu_RespL1C1( mu_adr, mu_PutML1C1, (int)mu_m, (int)mu_directoryL1C1, mu_cbe.mu_cl );
mu_Send_req ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M_evict;
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_M_load(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
if (mu_cbe.mu_cl.isundefined())
  mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val.undefine();
else
  mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val = mu_cbe.mu_cl;
if ( (mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val) == (0) )
{
mu_loadedZeroCounter = (mu_loadedZeroCounter) + (1);
}
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_M_store(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m, const mu_1_ClValue& mu_v)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_Set_perm ( mu_store, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_M;
mu_Execute_store_monitor ( mu_cbe.mu_cl, mu_adr );
if (mu_v.isundefined())
  mu_cbe.mu_cl.undefine();
else
  mu_cbe.mu_cl = mu_v;
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_S_evict(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_msg = mu_RequestL1C1( mu_adr, mu_PutSL1C1, (int)mu_m, (int)mu_directoryL1C1 );
mu_Send_req ( mu_msg, (int)mu_m );
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_evict;
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_S_load(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_Set_perm ( mu_load, mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S;
if (mu_cbe.mu_cl.isundefined())
  mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val.undefine();
else
  mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val = mu_cbe.mu_cl;
if ( (mu_i_threadlist[mu_m][mu_i_threadIndexes[mu_m].mu_currentIndex].mu_val) == (0) )
{
mu_loadedZeroCounter = (mu_loadedZeroCounter) + (1);
}
}
};
/*** end procedure declaration ***/

void mu_FSM_Access_cacheL1C1_S_store(const mu_1_Address& mu_adr, const mu_1_OBJSET_cacheL1C1& mu_m, const mu_1_ClValue& mu_v)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

{
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_msg = mu_RequestL1C1( mu_adr, mu_GetML1C1, (int)mu_m, (int)mu_directoryL1C1 );
mu_Send_req ( mu_msg, (int)mu_m );
mu_cbe.mu_acksReceivedL1C1 = 0;
mu_Clear_perm ( mu_adr, (int)mu_m );
mu_cbe.mu_State = mu_cacheL1C1_S_store;
}
};
/*** end procedure declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_fwd.clear();
  mu_cnt_fwd.clear();
  mu_resp.clear();
  mu_cnt_resp.clear();
  mu_req.clear();
  mu_cnt_req.clear();
  mu_g_perm.clear();
  mu_g_monitor_store.clear();
  mu_i_directoryL1C1.clear();
  mu_i_cacheL1C1.clear();
  mu_i_thread1.clear();
  mu_i_thread2.clear();
  mu_i_thread3.clear();
  mu_i_threadlist.clear();
  mu_i_threadIndexes.clear();
  mu_initializer.clear();
  mu_loadedZeroCounter.clear();
  mu_instructionsExecuted.clear();
}
void world_class::undefine()
{
  mu_fwd.undefine();
  mu_cnt_fwd.undefine();
  mu_resp.undefine();
  mu_cnt_resp.undefine();
  mu_req.undefine();
  mu_cnt_req.undefine();
  mu_g_perm.undefine();
  mu_g_monitor_store.undefine();
  mu_i_directoryL1C1.undefine();
  mu_i_cacheL1C1.undefine();
  mu_i_thread1.undefine();
  mu_i_thread2.undefine();
  mu_i_thread3.undefine();
  mu_i_threadlist.undefine();
  mu_i_threadIndexes.undefine();
  mu_initializer.undefine();
  mu_loadedZeroCounter.undefine();
  mu_instructionsExecuted.undefine();
}
void world_class::reset()
{
  mu_fwd.reset();
  mu_cnt_fwd.reset();
  mu_resp.reset();
  mu_cnt_resp.reset();
  mu_req.reset();
  mu_cnt_req.reset();
  mu_g_perm.reset();
  mu_g_monitor_store.reset();
  mu_i_directoryL1C1.reset();
  mu_i_cacheL1C1.reset();
  mu_i_thread1.reset();
  mu_i_thread2.reset();
  mu_i_thread3.reset();
  mu_i_threadlist.reset();
  mu_i_threadIndexes.reset();
  mu_initializer.reset();
  mu_loadedZeroCounter.reset();
  mu_instructionsExecuted.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_fwd.print();
  mu_cnt_fwd.print();
  mu_resp.print();
  mu_cnt_resp.print();
  mu_req.print();
  mu_cnt_req.print();
  mu_g_perm.print();
  mu_g_monitor_store.print();
  mu_i_directoryL1C1.print();
  mu_i_cacheL1C1.print();
  mu_i_thread1.print();
  mu_i_thread2.print();
  mu_i_thread3.print();
  mu_i_threadlist.print();
  mu_i_threadIndexes.print();
  mu_initializer.print();
  mu_loadedZeroCounter.print();
  mu_instructionsExecuted.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_fwd.print_statistic();
  mu_cnt_fwd.print_statistic();
  mu_resp.print_statistic();
  mu_cnt_resp.print_statistic();
  mu_req.print_statistic();
  mu_cnt_req.print_statistic();
  mu_g_perm.print_statistic();
  mu_g_monitor_store.print_statistic();
  mu_i_directoryL1C1.print_statistic();
  mu_i_cacheL1C1.print_statistic();
  mu_i_thread1.print_statistic();
  mu_i_thread2.print_statistic();
  mu_i_thread3.print_statistic();
  mu_i_threadlist.print_statistic();
  mu_i_threadIndexes.print_statistic();
  mu_initializer.print_statistic();
  mu_loadedZeroCounter.print_statistic();
  mu_instructionsExecuted.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_fwd.print_diff(prevstate);
    mu_cnt_fwd.print_diff(prevstate);
    mu_resp.print_diff(prevstate);
    mu_cnt_resp.print_diff(prevstate);
    mu_req.print_diff(prevstate);
    mu_cnt_req.print_diff(prevstate);
    mu_g_perm.print_diff(prevstate);
    mu_g_monitor_store.print_diff(prevstate);
    mu_i_directoryL1C1.print_diff(prevstate);
    mu_i_cacheL1C1.print_diff(prevstate);
    mu_i_thread1.print_diff(prevstate);
    mu_i_thread2.print_diff(prevstate);
    mu_i_thread3.print_diff(prevstate);
    mu_i_threadlist.print_diff(prevstate);
    mu_i_threadIndexes.print_diff(prevstate);
    mu_initializer.print_diff(prevstate);
    mu_loadedZeroCounter.print_diff(prevstate);
    mu_instructionsExecuted.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_fwd.to_state( newstate );
  mu_cnt_fwd.to_state( newstate );
  mu_resp.to_state( newstate );
  mu_cnt_resp.to_state( newstate );
  mu_req.to_state( newstate );
  mu_cnt_req.to_state( newstate );
  mu_g_perm.to_state( newstate );
  mu_g_monitor_store.to_state( newstate );
  mu_i_directoryL1C1.to_state( newstate );
  mu_i_cacheL1C1.to_state( newstate );
  mu_i_thread1.to_state( newstate );
  mu_i_thread2.to_state( newstate );
  mu_i_thread3.to_state( newstate );
  mu_i_threadlist.to_state( newstate );
  mu_i_threadIndexes.to_state( newstate );
  mu_initializer.to_state( newstate );
  mu_loadedZeroCounter.to_state( newstate );
  mu_instructionsExecuted.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive resp, src:%s, dst:%s", mu_src.Name(), mu_dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_resp[mu_dst][0];
    return (mu_cnt_resp[mu_dst]) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 16 )
      {
	if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_resp[mu_dst][0];
	      if ((mu_cnt_resp[mu_dst]) > (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 0;
    mu_src.unionassign(r % 4);
    r = r / 4;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_resp[mu_dst][0];
if ( (mu_dst>=39 && mu_dst<=39) )
{
if ( mu_FSM_MSG_directoryL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_resp ( mu_dst, mu_src );
}
}
else
{
if ( (mu_dst>=36 && mu_dst<=38) )
{
if ( mu_FSM_MSG_cacheL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_resp ( mu_dst, mu_src );
}
}
else
{
Error.Error("Error: unknown machine");
}
}
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive req, src:%s, dst:%s", mu_src.Name(), mu_dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_req[mu_dst][0];
    return (mu_cnt_req[mu_dst]) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 32 )
      {
	if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_req[mu_dst][0];
	      if ((mu_cnt_req[mu_dst]) > (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 16;
    mu_src.unionassign(r % 4);
    r = r / 4;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_req[mu_dst][0];
if ( (mu_dst>=39 && mu_dst<=39) )
{
if ( mu_FSM_MSG_directoryL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_req ( mu_dst, mu_src );
}
}
else
{
if ( (mu_dst>=36 && mu_dst<=38) )
{
if ( mu_FSM_MSG_cacheL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_req ( mu_dst, mu_src );
}
}
else
{
Error.Error("Error: unknown machine");
}
}
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    return tsprintf("Receive fwd, src:%s, dst:%s", mu_src.Name(), mu_dst.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_fwd[mu_dst][0];
    return (mu_cnt_fwd[mu_dst]) > (0);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 32;
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 48 )
      {
	if ( ( TRUE  ) ) {
  mu_1_Message& mu_msg = mu_fwd[mu_dst][0];
	      if ((mu_cnt_fwd[mu_dst]) > (0)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 4;
	}
	else
	  what_rule += 4;
    r = what_rule - 32;
    mu_src.unionassign(r % 4);
    r = r / 4;
    mu_dst.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Machines mu_src;
    mu_src.unionassign(r % 4);
    r = r / 4;
    static mu_1_Machines mu_dst;
    mu_dst.unionassign(r % 4);
    r = r / 4;
  mu_1_Message& mu_msg = mu_fwd[mu_dst][0];
if ( (mu_dst>=39 && mu_dst<=39) )
{
if ( mu_FSM_MSG_directoryL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_fwd ( mu_dst, mu_src );
}
}
else
{
if ( (mu_dst>=36 && mu_dst<=38) )
{
if ( mu_FSM_MSG_cacheL1C1( mu_msg, (int)mu_dst ) )
{
mu_Pop_fwd ( mu_dst, mu_src );
}
}
else
{
Error.Error("Error: unknown machine");
}
}
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_S_store, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr28;
bool mu__boolexpr29;
bool mu__boolexpr30;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr29)) mu__boolexpr28 = FALSE ;
  else {
  mu__boolexpr28 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
    return mu__boolexpr28;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 48;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 51 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr31;
bool mu__boolexpr32;
bool mu__boolexpr33;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr33)) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
	      if (mu__boolexpr31) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 48;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_S_store ( mu_adr, mu_m, mu_currentThread[mu_threadIndex].mu_val );
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_S_evict, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr34;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = (mu_req_network_ready(  )) ; 
}
    return mu__boolexpr34;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 51;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 54 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr35;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = (mu_req_network_ready(  )) ; 
}
	      if (mu__boolexpr35) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 51;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_S_evict ( mu_adr, mu_m );
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_S_load, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr36;
bool mu__boolexpr37;
bool mu__boolexpr38;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr37)) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
    return mu__boolexpr36;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 54;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 57 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr39;
bool mu__boolexpr40;
bool mu__boolexpr41;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_S))) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr41)) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
	      if (mu__boolexpr39) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 54;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_S_load ( mu_adr, mu_m );
mu_i_threadIndexes[mu_m].mu_currentIndex = (mu_threadIndex) + (1);
mu_instructionsExecuted = (mu_instructionsExecuted) + (1);
if ( (mu_instructionsExecuted) == (6) )
{
mu_resetEverything (  );
}
  };

};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_M_store, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr42;
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr43)) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
    return mu__boolexpr42;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 57;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 60 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr45;
bool mu__boolexpr46;
bool mu__boolexpr47;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr47)) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
	      if (mu__boolexpr45) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 57;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_M_store ( mu_adr, mu_m, mu_currentThread[mu_threadIndex].mu_val );
mu_i_threadIndexes[mu_m].mu_currentIndex = (mu_threadIndex) + (1);
mu_instructionsExecuted = (mu_instructionsExecuted) + (1);
if ( (mu_instructionsExecuted) == (6) )
{
mu_resetEverything (  );
}
  };

};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_M_evict, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr48;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = (mu_req_network_ready(  )) ; 
}
    return mu__boolexpr48;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 60;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 63 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr49;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = (mu_req_network_ready(  )) ; 
}
	      if (mu__boolexpr49) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 60;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_M_evict ( mu_adr, mu_m );
  };

};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_M_load, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr50;
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr51)) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
    return mu__boolexpr50;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 63;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 66 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr53;
bool mu__boolexpr54;
bool mu__boolexpr55;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_M))) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr55)) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
	      if (mu__boolexpr53) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 63;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_M_load ( mu_adr, mu_m );
mu_i_threadIndexes[mu_m].mu_currentIndex = (mu_threadIndex) + (1);
mu_instructionsExecuted = (mu_instructionsExecuted) + (1);
if ( (mu_instructionsExecuted) == (6) )
{
mu_resetEverything (  );
}
  };

};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_I_store, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr56;
bool mu__boolexpr57;
bool mu__boolexpr58;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_I))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr58)) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr57)) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
    return mu__boolexpr56;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 66;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 69 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr59;
bool mu__boolexpr60;
bool mu__boolexpr61;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_I))) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr61)) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr60)) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_store)) ; 
}
	      if (mu__boolexpr59) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 66;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_I_store ( mu_adr, mu_m, mu_currentThread[mu_threadIndex].mu_val );
  };

};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    return tsprintf("cacheL1C1_I_load, m:%s", mu_m.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr62;
bool mu__boolexpr63;
bool mu__boolexpr64;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_I))) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr64)) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr63)) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
    return mu__boolexpr62;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 69;
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    while (what_rule < 72 )
      {
	if ( ( TRUE  ) ) {
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
bool mu__boolexpr65;
bool mu__boolexpr66;
bool mu__boolexpr67;
  if (!((mu_cbe.mu_State) == (mu_cacheL1C1_I))) mu__boolexpr67 = FALSE ;
  else {
  mu__boolexpr67 = (mu_req_network_ready(  )) ; 
}
  if (!(mu__boolexpr67)) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_threadIndex) <= (mu_i_threadIndexes[mu_m].mu_maxIndex)) ; 
}
  if (!(mu__boolexpr66)) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_currentThread[mu_threadIndex].mu_itype) == (mu_load)) ; 
}
	      if (mu__boolexpr65) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 69;
    mu_m.value((r % 3) + 36);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_OBJSET_cacheL1C1 mu_m;
    mu_m.value((r % 3) + 36);
    r = r / 3;
  mu_1_thread& mu_currentThread = mu_i_threadlist[mu_m];
  mu_1__type_0& mu_threadIndex = mu_i_threadIndexes[mu_m].mu_currentIndex;
  mu_1_Address& mu_adr = mu_currentThread[mu_threadIndex].mu_adr;
  mu_1_ENTRY_cacheL1C1& mu_cbe = mu_i_cacheL1C1[mu_m].mu_cb[mu_adr];
mu_FSM_Access_cacheL1C1_I_load ( mu_adr, mu_m );
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<16)
    { R0.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<32)
    { R1.NextRule(what_rule);
      if (what_rule<32) return; }
  if (what_rule>=32 && what_rule<48)
    { R2.NextRule(what_rule);
      if (what_rule<48) return; }
  if (what_rule>=48 && what_rule<51)
    { R3.NextRule(what_rule);
      if (what_rule<51) return; }
  if (what_rule>=51 && what_rule<54)
    { R4.NextRule(what_rule);
      if (what_rule<54) return; }
  if (what_rule>=54 && what_rule<57)
    { R5.NextRule(what_rule);
      if (what_rule<57) return; }
  if (what_rule>=57 && what_rule<60)
    { R6.NextRule(what_rule);
      if (what_rule<60) return; }
  if (what_rule>=60 && what_rule<63)
    { R7.NextRule(what_rule);
      if (what_rule<63) return; }
  if (what_rule>=63 && what_rule<66)
    { R8.NextRule(what_rule);
      if (what_rule<66) return; }
  if (what_rule>=66 && what_rule<69)
    { R9.NextRule(what_rule);
      if (what_rule<69) return; }
  if (what_rule>=69 && what_rule<72)
    { R10.NextRule(what_rule);
      if (what_rule<72) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=15) return R0.Condition(r-0);
  if (r>=16 && r<=31) return R1.Condition(r-16);
  if (r>=32 && r<=47) return R2.Condition(r-32);
  if (r>=48 && r<=50) return R3.Condition(r-48);
  if (r>=51 && r<=53) return R4.Condition(r-51);
  if (r>=54 && r<=56) return R5.Condition(r-54);
  if (r>=57 && r<=59) return R6.Condition(r-57);
  if (r>=60 && r<=62) return R7.Condition(r-60);
  if (r>=63 && r<=65) return R8.Condition(r-63);
  if (r>=66 && r<=68) return R9.Condition(r-66);
  if (r>=69 && r<=71) return R10.Condition(r-69);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=15) { R0.Code(r-0); return; } 
  if (r>=16 && r<=31) { R1.Code(r-16); return; } 
  if (r>=32 && r<=47) { R2.Code(r-32); return; } 
  if (r>=48 && r<=50) { R3.Code(r-48); return; } 
  if (r>=51 && r<=53) { R4.Code(r-51); return; } 
  if (r>=54 && r<=56) { R5.Code(r-54); return; } 
  if (r>=57 && r<=59) { R6.Code(r-57); return; } 
  if (r>=60 && r<=62) { R7.Code(r-60); return; } 
  if (r>=63 && r<=65) { R8.Code(r-63); return; } 
  if (r>=66 && r<=68) { R9.Code(r-66); return; } 
  if (r>=69 && r<=71) { R10.Code(r-69); return; } 
}
int Priority(unsigned short r)
{
  if (r<=15) { return R0.Priority(); } 
  if (r>=16 && r<=31) { return R1.Priority(); } 
  if (r>=32 && r<=47) { return R2.Priority(); } 
  if (r>=48 && r<=50) { return R3.Priority(); } 
  if (r>=51 && r<=53) { return R4.Priority(); } 
  if (r>=54 && r<=56) { return R5.Priority(); } 
  if (r>=57 && r<=59) { return R6.Priority(); } 
  if (r>=60 && r<=62) { return R7.Priority(); } 
  if (r>=63 && r<=65) { return R8.Priority(); } 
  if (r>=66 && r<=68) { return R9.Priority(); } 
  if (r>=69 && r<=71) { return R10.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=15) return R0.Name(r-0);
  if (r>=16 && r<=31) return R1.Name(r-16);
  if (r>=32 && r<=47) return R2.Name(r-32);
  if (r>=48 && r<=50) return R3.Name(r-48);
  if (r>=51 && r<=53) return R4.Name(r-51);
  if (r>=54 && r<=56) return R5.Name(r-54);
  if (r>=57 && r<=59) return R6.Name(r-57);
  if (r>=60 && r<=62) return R7.Name(r-60);
  if (r>=63 && r<=65) return R8.Name(r-63);
  if (r>=66 && r<=68) return R9.Name(r-66);
  if (r>=69 && r<=71) return R10.Name(r-69);
  return NULL;
}
};
const unsigned numrules = 72;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 72


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
mu_loadedZeroCounter = 0;
mu_resetEverything (  );
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_68() // Invariant "Store excludes load check"
{
bool mu__quant69; 
mu__quant69 = TRUE;
{
for(int mu_a = 0; mu_a <= 2; mu_a++) {
bool mu__quant70; 
mu__quant70 = TRUE;
{
for(int mu_m1 = 36; mu_m1 <= 39; mu_m1++)
  if (( ( mu_m1 >= 39 ) && ( mu_m1 <= 39 ) )|| ( ( mu_m1 >= 36 ) && ( mu_m1 <= 38 ) )) {
bool mu__quant71; 
mu__quant71 = TRUE;
{
for(int mu_m2 = 36; mu_m2 <= 39; mu_m2++)
  if (( ( mu_m2 >= 39 ) && ( mu_m2 <= 39 ) )|| ( ( mu_m2 >= 36 ) && ( mu_m2 <= 38 ) )) {
bool mu__boolexpr72;
bool mu__boolexpr73;
  if (!((mu_m1) != (mu_m2))) mu__boolexpr73 = FALSE ;
  else {
/*** begin multisetcount 9 declaration ***/
  int mu__intexpr74 = 0;
  {
  mu_1_acc_type_obj_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_g_perm[mu_m1][mu_a].valid[(int)mu_i].value())
	{
	  if ( (mu_g_perm[mu_m1][mu_a][mu_i]) == (mu_store) ) mu__intexpr74++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 9 declaration ***/
  mu__boolexpr73 = ((mu__intexpr74) > (0)) ; 
}
  if (!(mu__boolexpr73)) mu__boolexpr72 = TRUE ;
  else {
/*** begin multisetcount 10 declaration ***/
  int mu__intexpr75 = 0;
  {
  mu_1_acc_type_obj_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_g_perm[mu_m2][mu_a].valid[(int)mu_i].value())
	{
	  if ( (mu_g_perm[mu_m2][mu_a][mu_i]) == (mu_load) ) mu__intexpr75++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 10 declaration ***/
  mu__boolexpr72 = ((mu__intexpr75) == (0)) ; 
}
if ( !(mu__boolexpr72) )
  { mu__quant71 = FALSE; break; }
};
};
if ( !(mu__quant71) )
  { mu__quant70 = FALSE; break; }
};
};
if ( !(mu__quant70) )
  { mu__quant69 = FALSE; break; }
};
};
return mu__quant69;
};

bool mu__condition_76() // Condition for Rule "Store excludes load check"
{
  return mu__invariant_68( );
}

/**** end rule declaration ****/

int mu__invariant_77() // Invariant "Exclusive store check"
{
bool mu__quant78; 
mu__quant78 = TRUE;
{
for(int mu_a = 0; mu_a <= 2; mu_a++) {
bool mu__quant79; 
mu__quant79 = TRUE;
{
for(int mu_m1 = 36; mu_m1 <= 39; mu_m1++)
  if (( ( mu_m1 >= 39 ) && ( mu_m1 <= 39 ) )|| ( ( mu_m1 >= 36 ) && ( mu_m1 <= 38 ) )) {
bool mu__quant80; 
mu__quant80 = TRUE;
{
for(int mu_m2 = 36; mu_m2 <= 39; mu_m2++)
  if (( ( mu_m2 >= 39 ) && ( mu_m2 <= 39 ) )|| ( ( mu_m2 >= 36 ) && ( mu_m2 <= 38 ) )) {
bool mu__boolexpr81;
bool mu__boolexpr82;
  if (!((mu_m1) != (mu_m2))) mu__boolexpr82 = FALSE ;
  else {
/*** begin multisetcount 7 declaration ***/
  int mu__intexpr83 = 0;
  {
  mu_1_acc_type_obj_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_g_perm[mu_m1][mu_a].valid[(int)mu_i].value())
	{
	  if ( (mu_g_perm[mu_m1][mu_a][mu_i]) == (mu_store) ) mu__intexpr83++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 7 declaration ***/
  mu__boolexpr82 = ((mu__intexpr83) > (0)) ; 
}
  if (!(mu__boolexpr82)) mu__boolexpr81 = TRUE ;
  else {
/*** begin multisetcount 8 declaration ***/
  int mu__intexpr84 = 0;
  {
  mu_1_acc_type_obj_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_g_perm[mu_m2][mu_a].valid[(int)mu_i].value())
	{
	  if ( (mu_g_perm[mu_m2][mu_a][mu_i]) == (mu_store) ) mu__intexpr84++;
	}
      if (mu_i == 3-1) break;
    }
  }
/*** end multisetcount 8 declaration ***/
  mu__boolexpr81 = ((mu__intexpr84) == (0)) ; 
}
if ( !(mu__boolexpr81) )
  { mu__quant80 = FALSE; break; }
};
};
if ( !(mu__quant80) )
  { mu__quant79 = FALSE; break; }
};
};
if ( !(mu__quant79) )
  { mu__quant78 = FALSE; break; }
};
};
return mu__quant78;
};

bool mu__condition_85() // Condition for Rule "Exclusive store check"
{
  return mu__invariant_77( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"Exclusive store check", &mu__condition_85, NULL, },
{"Store excludes load check", &mu__condition_76, NULL, },
};
const unsigned short numinvariants = 2;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
i_thread2:NoScalarset
g_monitor_store:NoScalarset
i_thread1:NoScalarset
i_thread3:NoScalarset
initializer:NoScalarset
loadedZeroCounter:NoScalarset
instructionsExecuted:NoScalarset
i_threadlist:ScalarsetArrayOfFree
i_cacheL1C1:ScalarsetArrayOfFree
cnt_req:ScalarsetArrayOfFree
cnt_resp:ScalarsetArrayOfFree
cnt_fwd:ScalarsetArrayOfFree
i_threadIndexes:ScalarsetArrayOfFree
fwd:ScalarsetArrayOfScalarset
resp:ScalarsetArrayOfScalarset
req:ScalarsetArrayOfScalarset
g_perm:Complex
i_directoryL1C1:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_OBJSET_cacheL1C1[3];
  int undefined_class_mu_1_OBJSET_cacheL1C1;// has the highest class number

  void Print_class_mu_1_OBJSET_cacheL1C1();
  bool OnlyOneRemain_mu_1_OBJSET_cacheL1C1;
  bool MTO_class_mu_1_OBJSET_cacheL1C1()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_OBJSET_cacheL1C1)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_OBJSET_cacheL1C1[i]== class_mu_1_OBJSET_cacheL1C1[j])
	    return TRUE;
    OnlyOneRemain_mu_1_OBJSET_cacheL1C1 = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_OBJSET_cacheL1C1;
  typedef int arr_mu_1_OBJSET_cacheL1C1[3];
  arr_mu_1_OBJSET_cacheL1C1 * perm_mu_1_OBJSET_cacheL1C1;
  arr_mu_1_OBJSET_cacheL1C1 * revperm_mu_1_OBJSET_cacheL1C1;

  int size_mu_1_OBJSET_cacheL1C1[3];
  bool reversed_sorted_mu_1_OBJSET_cacheL1C1(int start, int end);
  void reverse_reversed_mu_1_OBJSET_cacheL1C1(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_OBJSET_cacheL1C1* perm, int size, mu_1_OBJSET_cacheL1C1 k);
  void GenPerm0(mu_1_OBJSET_cacheL1C1* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_OBJSET_cacheL1C1()
{
  cout << "class_mu_1_OBJSET_cacheL1C1:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_OBJSET_cacheL1C1[i];
  cout << " " << undefined_class_mu_1_OBJSET_cacheL1C1 << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_OBJSET_cacheL1C1[i]== class_mu_1_OBJSET_cacheL1C1[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_OBJSET_cacheL1C1 Perm0[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[6];
 in_mu_1_OBJSET_cacheL1C1 = new int[6];
 perm_mu_1_OBJSET_cacheL1C1 = new arr_mu_1_OBJSET_cacheL1C1[6];
 revperm_mu_1_OBJSET_cacheL1C1 = new arr_mu_1_OBJSET_cacheL1C1[6];

    // Set perm and revperm
    count = 0;
    for (i=36; i<=38; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=36; j<=38; j++)
        for (k=36; k<=38; k++)
          if (revperm_mu_1_OBJSET_cacheL1C1[i][k-36]==j)   // k - base 
            perm_mu_1_OBJSET_cacheL1C1[i][j-36]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_OBJSET_cacheL1C1 = 0;
    size = 6;
    count = 6;
    for (i=0; i<6; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_OBJSET_cacheL1C1[i] = i_mu_1_OBJSET_cacheL1C1;
      i_mu_1_OBJSET_cacheL1C1 += carry;
      if (i_mu_1_OBJSET_cacheL1C1 >= 6) { i_mu_1_OBJSET_cacheL1C1 = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_OBJSET_cacheL1C1 = new int[1];
 perm_mu_1_OBJSET_cacheL1C1 = new arr_mu_1_OBJSET_cacheL1C1[1];
 revperm_mu_1_OBJSET_cacheL1C1 = new arr_mu_1_OBJSET_cacheL1C1[1];
  in[0] = TRUE;
    in_mu_1_OBJSET_cacheL1C1[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_OBJSET_cacheL1C1[i]=0;
  undefined_class_mu_1_OBJSET_cacheL1C1=0;
  OnlyOneRemain_mu_1_OBJSET_cacheL1C1 = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<6; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_OBJSET_cacheL1C1[3];
  int size_mu_1_OBJSET_cacheL1C1[3];
  bool should_be_in_mu_1_OBJSET_cacheL1C1[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cacheL1C1[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cacheL1C1[k]==j)
	  {
	    size_mu_1_OBJSET_cacheL1C1[k] = class_size;
	    start_mu_1_OBJSET_cacheL1C1[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_OBJSET_cacheL1C1[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_OBJSET_cacheL1C1[i][k]-36 >=start_mu_1_OBJSET_cacheL1C1[k] 
	     && perm_mu_1_OBJSET_cacheL1C1[i][k]-36 < start_mu_1_OBJSET_cacheL1C1[k] + size_mu_1_OBJSET_cacheL1C1[k]) )
  	    {
	      should_be_in_mu_1_OBJSET_cacheL1C1[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<6; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_OBJSET_cacheL1C1[in_mu_1_OBJSET_cacheL1C1[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cacheL1C1[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_OBJSET_cacheL1C1[k]==j)
	  {
	    size_mu_1_OBJSET_cacheL1C1[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_OBJSET_cacheL1C1[k]==j)
	      revperm_mu_1_OBJSET_cacheL1C1[0][start++] = k+36;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_OBJSET_cacheL1C1[0][k]==j+36)
        perm_mu_1_OBJSET_cacheL1C1[0][j]=k+36;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_OBJSET_cacheL1C1* Perm, int size, mu_1_OBJSET_cacheL1C1 k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_OBJSET_cacheL1C1* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=36; i<=38; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=36; i<=38; i++)
        revperm_mu_1_OBJSET_cacheL1C1[count][i-36]=Perm[i-36].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_OBJSET_cacheL1C1(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_OBJSET_cacheL1C1[0][i]<revperm_mu_1_OBJSET_cacheL1C1[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_OBJSET_cacheL1C1(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_OBJSET_cacheL1C1[0][j];
      revperm_mu_1_OBJSET_cacheL1C1[0][j] = revperm_mu_1_OBJSET_cacheL1C1[0][i];
      revperm_mu_1_OBJSET_cacheL1C1[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_OBJSET_cacheL1C1[revperm_mu_1_OBJSET_cacheL1C1[0][start]-36];
      if (reversed_sorted_mu_1_OBJSET_cacheL1C1(start,end))
	       {
	  reverse_reversed_mu_1_OBJSET_cacheL1C1(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_OBJSET_cacheL1C1(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_OBJSET_cacheL1C1[0][j]<revperm_mu_1_OBJSET_cacheL1C1[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_OBJSET_cacheL1C1[0][j];
			  revperm_mu_1_OBJSET_cacheL1C1[0][j] = revperm_mu_1_OBJSET_cacheL1C1[0][k];
			  revperm_mu_1_OBJSET_cacheL1C1[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_OBJSET_cacheL1C1(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_OBJSET_cacheL1C1[0][k]==j+36)   // k - base 
	perm_mu_1_OBJSET_cacheL1C1[0][j]=k+36; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_i_thread2.MultisetSort();
        mu_g_monitor_store.MultisetSort();
        mu_i_thread1.MultisetSort();
        mu_i_thread3.MultisetSort();
        mu_initializer.MultisetSort();
        mu_loadedZeroCounter.MultisetSort();
        mu_instructionsExecuted.MultisetSort();
        mu_i_threadlist.MultisetSort();
        mu_i_cacheL1C1.MultisetSort();
        mu_cnt_req.MultisetSort();
        mu_cnt_resp.MultisetSort();
        mu_cnt_fwd.MultisetSort();
        mu_i_threadIndexes.MultisetSort();
        mu_fwd.MultisetSort();
        mu_resp.MultisetSort();
        mu_req.MultisetSort();
        mu_g_perm.MultisetSort();
        mu_i_directoryL1C1.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Address::Permute(PermSet& Perm, int i) {};
void mu_1_Address::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Address::Canonicalize(PermSet& Perm) {};
void mu_1_Address::SimpleLimit(PermSet& Perm) {};
void mu_1_Address::ArrayLimit(PermSet& Perm) {};
void mu_1_Address::Limit(PermSet& Perm) {};
void mu_1_Address::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_ClValue::Permute(PermSet& Perm, int i) {};
void mu_1_ClValue::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ClValue::Canonicalize(PermSet& Perm) {};
void mu_1_ClValue::SimpleLimit(PermSet& Perm) {};
void mu_1_ClValue::ArrayLimit(PermSet& Perm) {};
void mu_1_ClValue::Limit(PermSet& Perm) {};
void mu_1_ClValue::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_PermissionType::Permute(PermSet& Perm, int i) {};
void mu_1_PermissionType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_PermissionType::Canonicalize(PermSet& Perm) {};
void mu_1_PermissionType::SimpleLimit(PermSet& Perm) {};
void mu_1_PermissionType::ArrayLimit(PermSet& Perm) {};
void mu_1_PermissionType::Limit(PermSet& Perm) {};
void mu_1_PermissionType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_s_cacheL1C1::Permute(PermSet& Perm, int i) {};
void mu_1_s_cacheL1C1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_s_cacheL1C1::Canonicalize(PermSet& Perm) {};
void mu_1_s_cacheL1C1::SimpleLimit(PermSet& Perm) {};
void mu_1_s_cacheL1C1::ArrayLimit(PermSet& Perm) {};
void mu_1_s_cacheL1C1::Limit(PermSet& Perm) {};
void mu_1_s_cacheL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_s_directoryL1C1::Permute(PermSet& Perm, int i) {};
void mu_1_s_directoryL1C1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_s_directoryL1C1::Canonicalize(PermSet& Perm) {};
void mu_1_s_directoryL1C1::SimpleLimit(PermSet& Perm) {};
void mu_1_s_directoryL1C1::ArrayLimit(PermSet& Perm) {};
void mu_1_s_directoryL1C1::Limit(PermSet& Perm) {};
void mu_1_s_directoryL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_OBJSET_cacheL1C1::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][value()-36]); // value - base
};
void mu_1_OBJSET_cacheL1C1::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]==Perm.undefined_class_mu_1_OBJSET_cacheL1C1) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == Perm.undefined_class_mu_1_OBJSET_cacheL1C1 && i!=value()-36)
            Perm.class_mu_1_OBJSET_cacheL1C1[i]++;
        value(36 + Perm.undefined_class_mu_1_OBJSET_cacheL1C1++);
      }
    else 
      {
        value(Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]+36);
      }
}
void mu_1_OBJSET_cacheL1C1::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_OBJSET_cacheL1C1::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]==Perm.undefined_class_mu_1_OBJSET_cacheL1C1) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == Perm.undefined_class_mu_1_OBJSET_cacheL1C1 && i!=value()-36)
            Perm.class_mu_1_OBJSET_cacheL1C1[i]++;
        Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
      }
}
void mu_1_OBJSET_cacheL1C1::ArrayLimit(PermSet& Perm) {}
void mu_1_OBJSET_cacheL1C1::Limit(PermSet& Perm) {}
void mu_1_OBJSET_cacheL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_OBJSET_directoryL1C1::Permute(PermSet& Perm, int i) {};
void mu_1_OBJSET_directoryL1C1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_OBJSET_directoryL1C1::Canonicalize(PermSet& Perm) {};
void mu_1_OBJSET_directoryL1C1::SimpleLimit(PermSet& Perm) {};
void mu_1_OBJSET_directoryL1C1::ArrayLimit(PermSet& Perm) {};
void mu_1_OBJSET_directoryL1C1::Limit(PermSet& Perm) {};
void mu_1_OBJSET_directoryL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_C1Machines::Permute(PermSet& Perm, int i) {}
void mu_1_C1Machines::SimpleCanonicalize(PermSet& Perm) {}
void mu_1_C1Machines::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_C1Machines::SimpleLimit(PermSet& Perm) {}
void mu_1_C1Machines::ArrayLimit(PermSet& Perm) {}
void mu_1_C1Machines::Limit(PermSet& Perm) {}
void mu_1_C1Machines::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_Machines::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 36 ) && ( value() <= 38 ) )
      value(Perm.perm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][value()-36]+(0)); // value - base
  }
}
void mu_1_Machines::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 36 ) && ( value() <= 38 ) )
      {
        if (Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]==Perm.undefined_class_mu_1_OBJSET_cacheL1C1) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == Perm.undefined_class_mu_1_OBJSET_cacheL1C1 && i!=value()-36)
                Perm.class_mu_1_OBJSET_cacheL1C1[i]++;
            value(36 + Perm.undefined_class_mu_1_OBJSET_cacheL1C1++);
          }
        else 
          {
            value(Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]+36);
          }
      }
  }
}
void mu_1_Machines::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Machines::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 36 ) && ( value() <= 38 ) )
      if (Perm.class_mu_1_OBJSET_cacheL1C1[value()-36]==Perm.undefined_class_mu_1_OBJSET_cacheL1C1) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == Perm.undefined_class_mu_1_OBJSET_cacheL1C1 && i!=value()-36)
              Perm.class_mu_1_OBJSET_cacheL1C1[i]++;
          Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
        }
  }
}
void mu_1_Machines::ArrayLimit(PermSet& Perm) {}
void mu_1_Machines::Limit(PermSet& Perm) {}
void mu_1_Machines::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_Instruction::Permute(PermSet& Perm, int i)
{
};
void mu_1_Instruction::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_Instruction::Canonicalize(PermSet& Perm)
{
};
void mu_1_Instruction::SimpleLimit(PermSet& Perm){}
void mu_1_Instruction::ArrayLimit(PermSet& Perm){}
void mu_1_Instruction::Limit(PermSet& Perm)
{
};
void mu_1_Instruction::MultisetLimit(PermSet& Perm)
{
};
void mu__subrange_14::Permute(PermSet& Perm, int i) {};
void mu__subrange_14::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_14::Canonicalize(PermSet& Perm) {};
void mu__subrange_14::SimpleLimit(PermSet& Perm) {};
void mu__subrange_14::ArrayLimit(PermSet& Perm) {};
void mu__subrange_14::Limit(PermSet& Perm) {};
void mu__subrange_14::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_thread::Permute(PermSet& Perm, int i)
{
  static mu_1_thread temp("Permute_mu_1_thread",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1_thread::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_thread::Canonicalize(PermSet& Perm){};
void mu_1_thread::SimpleLimit(PermSet& Perm){}
void mu_1_thread::ArrayLimit(PermSet& Perm) {}
void mu_1_thread::Limit(PermSet& Perm){}
void mu_1_thread::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_threadlist::Permute(PermSet& Perm, int i)
{
  static mu_1_threadlist temp("Permute_mu_1_threadlist",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];};
void mu_1_threadlist::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_threadlist::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1_thread value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_OBJSET_cacheL1C1[3];
  int start_mu_1_OBJSET_cacheL1C1[3];
  // canonicalization
  static mu_1_threadlist temp;
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              {
                size_mu_1_OBJSET_cacheL1C1[k] = class_size;
                start_mu_1_OBJSET_cacheL1C1[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cacheL1C1[j] 
             && i < start_mu_1_OBJSET_cacheL1C1[j] + size_mu_1_OBJSET_cacheL1C1[j])
           {
             array[i+0] = temp[j+36];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cacheL1C1[j]+0] = temp[j+36];
    }
}
void mu_1_threadlist::SimpleLimit(PermSet& Perm){}
void mu_1_threadlist::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1_thread value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_threadlist::Limit(PermSet& Perm){}
void mu_1_threadlist::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_1::Permute(PermSet& Perm, int i) {};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_1::Canonicalize(PermSet& Perm) {};
void mu_1__type_1::SimpleLimit(PermSet& Perm) {};
void mu_1__type_1::ArrayLimit(PermSet& Perm) {};
void mu_1__type_1::Limit(PermSet& Perm) {};
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{
};
void mu_1__type_2::SimpleLimit(PermSet& Perm){}
void mu_1__type_2::ArrayLimit(PermSet& Perm){}
void mu_1__type_2::Limit(PermSet& Perm)
{
};
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
};
void mu_1_threadIndexes::Permute(PermSet& Perm, int i)
{
  static mu_1_threadIndexes temp("Permute_mu_1_threadIndexes",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];};
void mu_1_threadIndexes::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_threadIndexes::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1__type_2 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_OBJSET_cacheL1C1[3];
  int start_mu_1_OBJSET_cacheL1C1[3];
  // canonicalization
  static mu_1_threadIndexes temp;
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              {
                size_mu_1_OBJSET_cacheL1C1[k] = class_size;
                start_mu_1_OBJSET_cacheL1C1[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cacheL1C1[j] 
             && i < start_mu_1_OBJSET_cacheL1C1[j] + size_mu_1_OBJSET_cacheL1C1[j])
           {
             array[i+0] = temp[j+36];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cacheL1C1[j]+0] = temp[j+36];
    }
}
void mu_1_threadIndexes::SimpleLimit(PermSet& Perm){}
void mu_1_threadIndexes::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1__type_2 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_threadIndexes::Limit(PermSet& Perm){}
void mu_1_threadIndexes::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_acc_type_obj::Permute(PermSet& Perm, int i)
{
  static mu_1_acc_type_obj temp("Permute_mu_1_acc_type_obj",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1_acc_type_obj::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1_acc_type_obj::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_acc_type_obj::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_acc_type_obj::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_acc_type_obj::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_acc_type_obj::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for multiset type of scalarset-free elements.\n"); };
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].Canonicalize(Perm);
}
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm) {}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_PermMonitor::Permute(PermSet& Perm, int i)
{
  static mu_1_PermMonitor temp("Permute_mu_1_PermMonitor",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];
};
void mu_1_PermMonitor::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_PermMonitor::Canonicalize(PermSet& Perm){};
void mu_1_PermMonitor::SimpleLimit(PermSet& Perm){}
void mu_1_PermMonitor::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_3 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_PermMonitor::Limit(PermSet& Perm){}
void mu_1_PermMonitor::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_GlobalStoreMonitor::Permute(PermSet& Perm, int i)
{
  static mu_1_GlobalStoreMonitor temp("Permute_mu_1_GlobalStoreMonitor",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1_GlobalStoreMonitor::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_GlobalStoreMonitor::Canonicalize(PermSet& Perm){};
void mu_1_GlobalStoreMonitor::SimpleLimit(PermSet& Perm){}
void mu_1_GlobalStoreMonitor::ArrayLimit(PermSet& Perm) {}
void mu_1_GlobalStoreMonitor::Limit(PermSet& Perm){}
void mu_1_GlobalStoreMonitor::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i) {};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_4::Canonicalize(PermSet& Perm) {};
void mu_1__type_4::SimpleLimit(PermSet& Perm) {};
void mu_1__type_4::ArrayLimit(PermSet& Perm) {};
void mu_1__type_4::Limit(PermSet& Perm) {};
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_dst.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_dst.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_dst.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu__subrange_27::Permute(PermSet& Perm, int i) {};
void mu__subrange_27::SimpleCanonicalize(PermSet& Perm) {};
void mu__subrange_27::Canonicalize(PermSet& Perm) {};
void mu__subrange_27::SimpleLimit(PermSet& Perm) {};
void mu__subrange_27::ArrayLimit(PermSet& Perm) {};
void mu__subrange_27::Limit(PermSet& Perm) {};
void mu__subrange_27::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_5::ArrayLimit(PermSet& Perm) {}
void mu_1__type_5::Limit(PermSet& Perm){}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_NET_Ordered::Permute(PermSet& Perm, int i)
{
  static mu_1_NET_Ordered temp("Permute_mu_1_NET_Ordered",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];
};
void mu_1_NET_Ordered::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_NET_Ordered::Canonicalize(PermSet& Perm){};
void mu_1_NET_Ordered::SimpleLimit(PermSet& Perm){}
void mu_1_NET_Ordered::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_5 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_NET_Ordered::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_5 value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_OBJSET_cacheL1C1, oldcount_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
  count_mu_1_OBJSET_cacheL1C1 = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == count_mu_1_OBJSET_cacheL1C1)
         {
           pos_mu_1_OBJSET_cacheL1C1[count_mu_1_OBJSET_cacheL1C1][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_OBJSET_cacheL1C1++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+36][i0].mu_src.isundefined()
            ||(*this)[k+36][i0].mu_src!=k+36)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] 
                    && !(*this)[k+36][i0].mu_src.isundefined()
                    && (*this)[k+36][i0].mu_src==k+36)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_OBJSET_cacheL1C1; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_OBJSET_cacheL1C1[j][k] = pos_mu_1_OBJSET_cacheL1C1[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                            pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                          if (pos_mu_1_OBJSET_cacheL1C1[i+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                            pos_mu_1_OBJSET_cacheL1C1[i+1][k] = FALSE;
                        }
                      count_mu_1_OBJSET_cacheL1C1++; i++;
                    }
                }
            }
        }
    }

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+36][i0].mu_dst.isundefined()
            ||(*this)[k+36][i0].mu_dst!=k+36)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] 
                    && !(*this)[k+36][i0].mu_dst.isundefined()
                    && (*this)[k+36][i0].mu_dst==k+36)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_OBJSET_cacheL1C1; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_OBJSET_cacheL1C1[j][k] = pos_mu_1_OBJSET_cacheL1C1[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                            pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                          if (pos_mu_1_OBJSET_cacheL1C1[i+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                            pos_mu_1_OBJSET_cacheL1C1[i+1][k] = FALSE;
                        }
                      count_mu_1_OBJSET_cacheL1C1++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3);
  while ( while_guard )
    {
      oldcount_mu_1_OBJSET_cacheL1C1 = count_mu_1_OBJSET_cacheL1C1;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+36][i0].mu_src.isundefined()
                &&(*this)[k+36][i0].mu_src!=k+36
                &&(*this)[k+36][i0].mu_src>=36
                &&(*this)[k+36][i0].mu_src<=38)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_OBJSET_cacheL1C1[i][k] 
                            && !(*this)[k+36][i0].mu_src.isundefined()
                            && (*this)[k+36][i0].mu_src!=k+36
                            && (*this)[k+36][i0].mu_src>=36
                            && (*this)[k+36][i0].mu_src<=38
                            && pos_mu_1_OBJSET_cacheL1C1[j][(*this)[k+36][i0].mu_src-36])
                          {
                            exists = TRUE;
                            goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_OBJSET_cacheL1C1; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_OBJSET_cacheL1C1[j][k] = pos_mu_1_OBJSET_cacheL1C1[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                                  if (pos_mu_1_OBJSET_cacheL1C1[i+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                                    pos_mu_1_OBJSET_cacheL1C1[i+1][k] = FALSE;                  
                                }
                              count_mu_1_OBJSET_cacheL1C1++;
                            }
                        }
                    }
                }
            }
        }

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+36][i0].mu_dst.isundefined()
                &&(*this)[k+36][i0].mu_dst!=k+36
                &&(*this)[k+36][i0].mu_dst>=36
                &&(*this)[k+36][i0].mu_dst<=38)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_OBJSET_cacheL1C1[i][k] 
                            && !(*this)[k+36][i0].mu_dst.isundefined()
                            && (*this)[k+36][i0].mu_dst!=k+36
                            && (*this)[k+36][i0].mu_dst>=36
                            && (*this)[k+36][i0].mu_dst<=38
                            && pos_mu_1_OBJSET_cacheL1C1[j][(*this)[k+36][i0].mu_dst-36])
                          {
                            exists = TRUE;
                            goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_OBJSET_cacheL1C1; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_OBJSET_cacheL1C1[j][k] = pos_mu_1_OBJSET_cacheL1C1[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_OBJSET_cacheL1C1[i][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                                  if (pos_mu_1_OBJSET_cacheL1C1[i+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                                    pos_mu_1_OBJSET_cacheL1C1[i+1][k] = FALSE;                  
                                }
                              count_mu_1_OBJSET_cacheL1C1++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_OBJSET_cacheL1C1!=count_mu_1_OBJSET_cacheL1C1);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_OBJSET_cacheL1C1<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_OBJSET_cacheL1C1[i][j])
            Perm.class_mu_1_OBJSET_cacheL1C1[j] = i;
      Perm.undefined_class_mu_1_OBJSET_cacheL1C1=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_OBJSET_cacheL1C1[j]>Perm.undefined_class_mu_1_OBJSET_cacheL1C1)
          Perm.undefined_class_mu_1_OBJSET_cacheL1C1=Perm.class_mu_1_OBJSET_cacheL1C1[j];
    }
}
void mu_1_NET_Ordered::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_6::Permute(PermSet& Perm, int i) {};
void mu_1__type_6::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_6::Canonicalize(PermSet& Perm) {};
void mu_1__type_6::SimpleLimit(PermSet& Perm) {};
void mu_1__type_6::ArrayLimit(PermSet& Perm) {};
void mu_1__type_6::Limit(PermSet& Perm) {};
void mu_1__type_6::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_NET_Ordered_cnt::Permute(PermSet& Perm, int i)
{
  static mu_1_NET_Ordered_cnt temp("Permute_mu_1_NET_Ordered_cnt",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
      (*this)[j].value(temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]].value());
};
void mu_1_NET_Ordered_cnt::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_NET_Ordered_cnt::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  static mu_1__type_6 value[4];
  int compare;
  // limit
  bool exists;
  bool split;
  // range mapping
  int start;
  int class_size;
  // canonicalization
  static mu_1_NET_Ordered_cnt temp;
  int count_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  int size_mu_1_OBJSET_cacheL1C1[3];
  int start_mu_1_OBJSET_cacheL1C1[3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j].value((*this)[i+36].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
                value[j].value((*this)[i+36].value());
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              {
                size_mu_1_OBJSET_cacheL1C1[k] = class_size;
                start_mu_1_OBJSET_cacheL1C1[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cacheL1C1[j] 
             && i < start_mu_1_OBJSET_cacheL1C1[j] + size_mu_1_OBJSET_cacheL1C1[j])
           {
             array[i+0].value(temp[j+36].value());
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cacheL1C1[j]+0].value(temp[j+36].value());
    }
}
void mu_1_NET_Ordered_cnt::SimpleLimit(PermSet& Perm){}
void mu_1_NET_Ordered_cnt::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_6 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k].value(value[k-1].value());
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j].value((*this)[i+36].value());
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
                value[j].value((*this)[i+36].value());
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_NET_Ordered_cnt::Limit(PermSet& Perm){}
void mu_1_NET_Ordered_cnt::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_7::Permute(PermSet& Perm, int i)
{
  static mu_1__type_7 temp("Permute_mu_1__type_7",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_7::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_7::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_7::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_7::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_7::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_7::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_OBJSET_cacheL1C1, oldcount_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[3][3];
  bool goodset_multisetindex[3];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 3; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 3; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 3; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
  count_mu_1_OBJSET_cacheL1C1 = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == count_mu_1_OBJSET_cacheL1C1)
         {
           pos_mu_1_OBJSET_cacheL1C1[count_mu_1_OBJSET_cacheL1C1][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_OBJSET_cacheL1C1++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_OBJSET_cacheL1C1 = count_mu_1_OBJSET_cacheL1C1;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=36
                && (*this)[k].mu_src<=38)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=36
                          && (*this)[k].mu_src<=38
                          && pos_mu_1_OBJSET_cacheL1C1[j][(*this)[k].mu_src-36])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_OBJSET_cacheL1C1[(*this)[k].mu_src-36] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_OBJSET_cacheL1C1; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_OBJSET_cacheL1C1[z][k] = pos_mu_1_OBJSET_cacheL1C1[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j][k] = FALSE;
                                if (pos_mu_1_OBJSET_cacheL1C1[j+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j+1][k] = FALSE;
                              }
                            count_mu_1_OBJSET_cacheL1C1++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_dst.isundefined())
                && (*this)[k].mu_dst>=36
                && (*this)[k].mu_dst<=38)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_dst.isundefined()
                          && (*this)[k].mu_dst>=36
                          && (*this)[k].mu_dst<=38
                          && pos_mu_1_OBJSET_cacheL1C1[j][(*this)[k].mu_dst-36])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_OBJSET_cacheL1C1[(*this)[k].mu_dst-36] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_OBJSET_cacheL1C1; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_OBJSET_cacheL1C1[z][k] = pos_mu_1_OBJSET_cacheL1C1[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j][k] = FALSE;
                                if (pos_mu_1_OBJSET_cacheL1C1[j+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j+1][k] = FALSE;
                              }
                            count_mu_1_OBJSET_cacheL1C1++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_OBJSET_cacheL1C1!=count_mu_1_OBJSET_cacheL1C1);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_OBJSET_cacheL1C1<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_OBJSET_cacheL1C1[i][j])
            Perm.class_mu_1_OBJSET_cacheL1C1[j] = i;
      Perm.undefined_class_mu_1_OBJSET_cacheL1C1=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_OBJSET_cacheL1C1[j]>Perm.undefined_class_mu_1_OBJSET_cacheL1C1)
          Perm.undefined_class_mu_1_OBJSET_cacheL1C1=Perm.class_mu_1_OBJSET_cacheL1C1[j];
    }
  }
}
void mu_1_NET_Unordered::Permute(PermSet& Perm, int i)
{
  static mu_1_NET_Unordered temp("Permute_mu_1_NET_Unordered",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];
};
void mu_1_NET_Unordered::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_NET_Unordered::Canonicalize(PermSet& Perm){};
void mu_1_NET_Unordered::SimpleLimit(PermSet& Perm){}
void mu_1_NET_Unordered::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_7 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_NET_Unordered::Limit(PermSet& Perm){}
void mu_1_NET_Unordered::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::Permute(PermSet& Perm, int i)
{
  static mu_1_v_directoryL1C1_cacheL1C1 temp("Permute_mu_1_v_directoryL1C1_cacheL1C1",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1_v_directoryL1C1_cacheL1C1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1_v_directoryL1C1_cacheL1C1::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Machines value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_OBJSET_cacheL1C1, oldcount_mu_1_OBJSET_cacheL1C1;
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[3][3];
  bool goodset_multisetindex[3];
  mu_1_Machines temp;

  // compact
  for (i = 0, j = 0; i < 3; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 3; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 3; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
  count_mu_1_OBJSET_cacheL1C1 = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_OBJSET_cacheL1C1[i] == count_mu_1_OBJSET_cacheL1C1)
         {
           pos_mu_1_OBJSET_cacheL1C1[count_mu_1_OBJSET_cacheL1C1][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_OBJSET_cacheL1C1++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_OBJSET_cacheL1C1 = count_mu_1_OBJSET_cacheL1C1;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].isundefined())
                && (*this)[k]>=36
                && (*this)[k]<=38)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].isundefined()
                          && (*this)[k]>=36
                          && (*this)[k]<=38
                          && pos_mu_1_OBJSET_cacheL1C1[j][(*this)[k]-36])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_OBJSET_cacheL1C1[(*this)[k]-36] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_OBJSET_cacheL1C1; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_OBJSET_cacheL1C1[z][k] = pos_mu_1_OBJSET_cacheL1C1[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_OBJSET_cacheL1C1[j][k] && !goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j][k] = FALSE;
                                if (pos_mu_1_OBJSET_cacheL1C1[j+1][k] && goodset_mu_1_OBJSET_cacheL1C1[k])
                                  pos_mu_1_OBJSET_cacheL1C1[j+1][k] = FALSE;
                              }
                            count_mu_1_OBJSET_cacheL1C1++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_OBJSET_cacheL1C1!=count_mu_1_OBJSET_cacheL1C1);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_OBJSET_cacheL1C1<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_OBJSET_cacheL1C1[i][j])
            Perm.class_mu_1_OBJSET_cacheL1C1[j] = i;
      Perm.undefined_class_mu_1_OBJSET_cacheL1C1=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_OBJSET_cacheL1C1[j]>Perm.undefined_class_mu_1_OBJSET_cacheL1C1)
          Perm.undefined_class_mu_1_OBJSET_cacheL1C1=Perm.class_mu_1_OBJSET_cacheL1C1[j];
    }
  }
}
void mu_1_cnt_v_directoryL1C1_cacheL1C1::Permute(PermSet& Perm, int i) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::Canonicalize(PermSet& Perm) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::SimpleLimit(PermSet& Perm) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::ArrayLimit(PermSet& Perm) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::Limit(PermSet& Perm) {};
void mu_1_cnt_v_directoryL1C1_cacheL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_ENTRY_directoryL1C1::Permute(PermSet& Perm, int i)
{
  mu_cacheL1C1.Permute(Perm,i);
  mu_ownerL1C1.Permute(Perm,i);
};
void mu_1_ENTRY_directoryL1C1::SimpleCanonicalize(PermSet& Perm)
{
  mu_ownerL1C1.SimpleCanonicalize(Perm);
};
void mu_1_ENTRY_directoryL1C1::Canonicalize(PermSet& Perm)
{
};
void mu_1_ENTRY_directoryL1C1::SimpleLimit(PermSet& Perm)
{
  mu_ownerL1C1.SimpleLimit(Perm);
};
void mu_1_ENTRY_directoryL1C1::ArrayLimit(PermSet& Perm){}
void mu_1_ENTRY_directoryL1C1::Limit(PermSet& Perm)
{
  mu_cacheL1C1.Limit(Perm);
};
void mu_1_ENTRY_directoryL1C1::MultisetLimit(PermSet& Perm)
{
  mu_cacheL1C1.MultisetLimit(Perm);
};
void mu_1__type_8::Permute(PermSet& Perm, int i)
{
  static mu_1__type_8 temp("Permute_mu_1__type_8",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_8::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_8::Canonicalize(PermSet& Perm){};
void mu_1__type_8::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_8::ArrayLimit(PermSet& Perm) {}
void mu_1__type_8::Limit(PermSet& Perm){}
void mu_1__type_8::MultisetLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].MultisetLimit(Perm);
  }
}
void mu_1_MACH_directoryL1C1::Permute(PermSet& Perm, int i)
{
  mu_cb.Permute(Perm,i);
};
void mu_1_MACH_directoryL1C1::SimpleCanonicalize(PermSet& Perm)
{
  mu_cb.SimpleCanonicalize(Perm);
};
void mu_1_MACH_directoryL1C1::Canonicalize(PermSet& Perm)
{
};
void mu_1_MACH_directoryL1C1::SimpleLimit(PermSet& Perm)
{
  mu_cb.SimpleLimit(Perm);
};
void mu_1_MACH_directoryL1C1::ArrayLimit(PermSet& Perm){}
void mu_1_MACH_directoryL1C1::Limit(PermSet& Perm)
{
  mu_cb.Limit(Perm);
};
void mu_1_MACH_directoryL1C1::MultisetLimit(PermSet& Perm)
{
  mu_cb.MultisetLimit(Perm);
};
void mu_1_OBJ_directoryL1C1::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_directoryL1C1 temp("Permute_mu_1_OBJ_directoryL1C1",-1);
  int j;
  for (j=0; j<1; j++)
    array[j].Permute(Perm, i);
};
void mu_1_OBJ_directoryL1C1::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<1; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1_OBJ_directoryL1C1::Canonicalize(PermSet& Perm){};
void mu_1_OBJ_directoryL1C1::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1_OBJ_directoryL1C1::ArrayLimit(PermSet& Perm) {}
void mu_1_OBJ_directoryL1C1::Limit(PermSet& Perm){}
void mu_1_OBJ_directoryL1C1::MultisetLimit(PermSet& Perm)
{
  for (int j=0; j<1; j++) {
    array[j].MultisetLimit(Perm);
  }
}
void mu_1__type_9::Permute(PermSet& Perm, int i) {};
void mu_1__type_9::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_9::Canonicalize(PermSet& Perm) {};
void mu_1__type_9::SimpleLimit(PermSet& Perm) {};
void mu_1__type_9::ArrayLimit(PermSet& Perm) {};
void mu_1__type_9::Limit(PermSet& Perm) {};
void mu_1__type_9::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_10::Permute(PermSet& Perm, int i) {};
void mu_1__type_10::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_10::Canonicalize(PermSet& Perm) {};
void mu_1__type_10::SimpleLimit(PermSet& Perm) {};
void mu_1__type_10::ArrayLimit(PermSet& Perm) {};
void mu_1__type_10::Limit(PermSet& Perm) {};
void mu_1__type_10::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_ENTRY_cacheL1C1::Permute(PermSet& Perm, int i)
{
};
void mu_1_ENTRY_cacheL1C1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_ENTRY_cacheL1C1::Canonicalize(PermSet& Perm)
{
};
void mu_1_ENTRY_cacheL1C1::SimpleLimit(PermSet& Perm){}
void mu_1_ENTRY_cacheL1C1::ArrayLimit(PermSet& Perm){}
void mu_1_ENTRY_cacheL1C1::Limit(PermSet& Perm)
{
};
void mu_1_ENTRY_cacheL1C1::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_11::Permute(PermSet& Perm, int i)
{
  static mu_1__type_11 temp("Permute_mu_1__type_11",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_11::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_11::Canonicalize(PermSet& Perm){};
void mu_1__type_11::SimpleLimit(PermSet& Perm){}
void mu_1__type_11::ArrayLimit(PermSet& Perm) {}
void mu_1__type_11::Limit(PermSet& Perm){}
void mu_1__type_11::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_MACH_cacheL1C1::Permute(PermSet& Perm, int i)
{
};
void mu_1_MACH_cacheL1C1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_MACH_cacheL1C1::Canonicalize(PermSet& Perm)
{
};
void mu_1_MACH_cacheL1C1::SimpleLimit(PermSet& Perm){}
void mu_1_MACH_cacheL1C1::ArrayLimit(PermSet& Perm){}
void mu_1_MACH_cacheL1C1::Limit(PermSet& Perm)
{
};
void mu_1_MACH_cacheL1C1::MultisetLimit(PermSet& Perm)
{
};
void mu_1_OBJ_cacheL1C1::Permute(PermSet& Perm, int i)
{
  static mu_1_OBJ_cacheL1C1 temp("Permute_mu_1_OBJ_cacheL1C1",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=36; j<=38; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_OBJSET_cacheL1C1[Perm.in_mu_1_OBJSET_cacheL1C1[i]][j-36]];};
void mu_1_OBJ_cacheL1C1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_OBJ_cacheL1C1::Canonicalize(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1_MACH_cacheL1C1 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // range mapping
  int start;
  int class_size;
  int size_mu_1_OBJSET_cacheL1C1[3];
  int start_mu_1_OBJSET_cacheL1C1[3];
  // canonicalization
  static mu_1_OBJ_cacheL1C1 temp;
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {

      // setup range for maping
      start = 0;
      for (j=0; j<=Perm.undefined_class_mu_1_OBJSET_cacheL1C1; j++) // class number
        {
          class_size = 0;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              class_size++;
          for (k=0; k<3; k++) // step through class[k]
            if (Perm.class_mu_1_OBJSET_cacheL1C1[k]==j)
              {
                size_mu_1_OBJSET_cacheL1C1[k] = class_size;
                start_mu_1_OBJSET_cacheL1C1[k] = start;
              }
          start+=class_size;
        }

      // canonicalize
      temp = *this;
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
         if (i >=start_mu_1_OBJSET_cacheL1C1[j] 
             && i < start_mu_1_OBJSET_cacheL1C1[j] + size_mu_1_OBJSET_cacheL1C1[j])
           {
             array[i+0] = temp[j+36];
             break;
           }
    }
  else
    {

      // fast canonicalize
      temp = *this;
      for (j=0; j<3; j++)
        array[Perm.class_mu_1_OBJSET_cacheL1C1[j]+0] = temp[j+36];
    }
}
void mu_1_OBJ_cacheL1C1::SimpleLimit(PermSet& Perm){}
void mu_1_OBJ_cacheL1C1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_OBJSET_cacheL1C1;
  int compare;
  static mu_1_MACH_cacheL1C1 value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_OBJSET_cacheL1C1[3];
  bool pos_mu_1_OBJSET_cacheL1C1[3][3];
  // sorting mu_1_OBJSET_cacheL1C1
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_OBJSET_cacheL1C1[i][j]=FALSE;
      count_mu_1_OBJSET_cacheL1C1 = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_OBJSET_cacheL1C1; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+36]);
              if (compare==0)
                {
                  pos_mu_1_OBJSET_cacheL1C1[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_OBJSET_cacheL1C1; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_OBJSET_cacheL1C1[k][z] = pos_mu_1_OBJSET_cacheL1C1[k-1][z];
                    }
                  value[j] = (*this)[i+36];
                  for (z=0; z<3; z++)
                    pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
                  pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
                  count_mu_1_OBJSET_cacheL1C1++;
                  break;
                }
            }
          if (j==count_mu_1_OBJSET_cacheL1C1)
            {
              value[j] = (*this)[i+36];
              for (z=0; z<3; z++)
                pos_mu_1_OBJSET_cacheL1C1[j][z] = FALSE;
              pos_mu_1_OBJSET_cacheL1C1[j][i] = TRUE;
              count_mu_1_OBJSET_cacheL1C1++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_OBJSET_cacheL1C1() && count_mu_1_OBJSET_cacheL1C1>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_OBJSET_cacheL1C1; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_OBJSET_cacheL1C1[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_OBJSET_cacheL1C1[i][k] && Perm.class_mu_1_OBJSET_cacheL1C1[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_OBJSET_cacheL1C1[k] = TRUE;
                    pos_mu_1_OBJSET_cacheL1C1[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_OBJSET_cacheL1C1[k]>j
                            || ( Perm.class_mu_1_OBJSET_cacheL1C1[k] == j && !goodset_mu_1_OBJSET_cacheL1C1[k] ) )
                          Perm.class_mu_1_OBJSET_cacheL1C1[k]++;
                      Perm.undefined_class_mu_1_OBJSET_cacheL1C1++;
                    }
                }
            }
        }
    }
}
void mu_1_OBJ_cacheL1C1::Limit(PermSet& Perm){}
void mu_1_OBJ_cacheL1C1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_12::Permute(PermSet& Perm, int i) {};
void mu_1__type_12::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_12::Canonicalize(PermSet& Perm) {};
void mu_1__type_12::SimpleLimit(PermSet& Perm) {};
void mu_1__type_12::ArrayLimit(PermSet& Perm) {};
void mu_1__type_12::Limit(PermSet& Perm) {};
void mu_1__type_12::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_13::Permute(PermSet& Perm, int i) {};
void mu_1__type_13::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_13::Canonicalize(PermSet& Perm) {};
void mu_1__type_13::SimpleLimit(PermSet& Perm) {};
void mu_1__type_13::ArrayLimit(PermSet& Perm) {};
void mu_1__type_13::Limit(PermSet& Perm) {};
void mu_1__type_13::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_14::Permute(PermSet& Perm, int i) {};
void mu_1__type_14::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_14::Canonicalize(PermSet& Perm) {};
void mu_1__type_14::SimpleLimit(PermSet& Perm) {};
void mu_1__type_14::ArrayLimit(PermSet& Perm) {};
void mu_1__type_14::Limit(PermSet& Perm) {};
void mu_1__type_14::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1__type_15::Permute(PermSet& Perm, int i) {};
void mu_1__type_15::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_15::Canonicalize(PermSet& Perm) {};
void mu_1__type_15::SimpleLimit(PermSet& Perm) {};
void mu_1__type_15::ArrayLimit(PermSet& Perm) {};
void mu_1__type_15::Limit(PermSet& Perm) {};
void mu_1__type_15::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_i_thread2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_thread2.MultisetSort();
              mu_g_monitor_store.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_monitor_store.MultisetSort();
              mu_i_thread1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_thread1.MultisetSort();
              mu_i_thread3.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_thread3.MultisetSort();
              mu_initializer.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_initializer.MultisetSort();
              mu_loadedZeroCounter.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_loadedZeroCounter.MultisetSort();
              mu_instructionsExecuted.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_instructionsExecuted.MultisetSort();
              mu_i_threadlist.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_threadlist.MultisetSort();
              mu_i_cacheL1C1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_cacheL1C1.MultisetSort();
              mu_cnt_req.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cnt_req.MultisetSort();
              mu_cnt_resp.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cnt_resp.MultisetSort();
              mu_cnt_fwd.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_cnt_fwd.MultisetSort();
              mu_i_threadIndexes.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_threadIndexes.MultisetSort();
              mu_fwd.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_fwd.MultisetSort();
              mu_resp.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_resp.MultisetSort();
              mu_req.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_g_perm.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_g_perm.MultisetSort();
              mu_i_directoryL1C1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_i_directoryL1C1.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_i_thread2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_thread2.MultisetSort();
          mu_g_monitor_store.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_monitor_store.MultisetSort();
          mu_i_thread1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_thread1.MultisetSort();
          mu_i_thread3.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_thread3.MultisetSort();
          mu_initializer.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_initializer.MultisetSort();
          mu_loadedZeroCounter.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_loadedZeroCounter.MultisetSort();
          mu_instructionsExecuted.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_instructionsExecuted.MultisetSort();
          mu_i_threadlist.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_threadlist.MultisetSort();
          mu_i_cacheL1C1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_cacheL1C1.MultisetSort();
          mu_cnt_req.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cnt_req.MultisetSort();
          mu_cnt_resp.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cnt_resp.MultisetSort();
          mu_cnt_fwd.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_cnt_fwd.MultisetSort();
          mu_i_threadIndexes.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_threadIndexes.MultisetSort();
          mu_fwd.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_fwd.MultisetSort();
          mu_resp.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_resp.MultisetSort();
          mu_req.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_req.MultisetSort();
          mu_g_perm.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_g_perm.MultisetSort();
          mu_i_directoryL1C1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_i_directoryL1C1.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_i_thread2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_thread2.MultisetSort();
              mu_g_monitor_store.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_monitor_store.MultisetSort();
              mu_i_thread1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_thread1.MultisetSort();
              mu_i_thread3.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_thread3.MultisetSort();
              mu_initializer.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_initializer.MultisetSort();
              mu_loadedZeroCounter.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_loadedZeroCounter.MultisetSort();
              mu_instructionsExecuted.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_instructionsExecuted.MultisetSort();
              mu_i_threadlist.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_threadlist.MultisetSort();
              mu_i_cacheL1C1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_cacheL1C1.MultisetSort();
              mu_cnt_req.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cnt_req.MultisetSort();
              mu_cnt_resp.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cnt_resp.MultisetSort();
              mu_cnt_fwd.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_cnt_fwd.MultisetSort();
              mu_i_threadIndexes.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_threadIndexes.MultisetSort();
              mu_fwd.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_fwd.MultisetSort();
              mu_resp.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_resp.MultisetSort();
              mu_req.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_req.MultisetSort();
              mu_g_perm.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_g_perm.MultisetSort();
              mu_i_directoryL1C1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_i_directoryL1C1.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_i_thread2.MultisetSort();
      mu_g_monitor_store.MultisetSort();
      mu_i_thread1.MultisetSort();
      mu_i_thread3.MultisetSort();
      mu_initializer.MultisetSort();
      mu_loadedZeroCounter.MultisetSort();
      mu_instructionsExecuted.MultisetSort();
      mu_i_threadlist.MultisetSort();
      mu_i_cacheL1C1.MultisetSort();
      mu_cnt_req.MultisetSort();
      mu_cnt_resp.MultisetSort();
      mu_cnt_fwd.MultisetSort();
      mu_i_threadIndexes.MultisetSort();
      mu_fwd.MultisetSort();
      mu_resp.MultisetSort();
      mu_req.MultisetSort();
      mu_g_perm.MultisetSort();
      mu_i_directoryL1C1.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_thread2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_thread2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_g_monitor_store.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_g_monitor_store.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_thread1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_thread1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_thread3.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_thread3.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_initializer.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_initializer.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_loadedZeroCounter.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_loadedZeroCounter.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_instructionsExecuted.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_instructionsExecuted.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_threadlist.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_threadlist.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_cacheL1C1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_cacheL1C1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cnt_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cnt_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cnt_resp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cnt_resp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_cnt_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_cnt_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_threadIndexes.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_threadIndexes.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_resp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_resp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_g_perm.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_g_perm.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_directoryL1C1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_directoryL1C1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_i_threadlist.Canonicalize(Perm);

  mu_i_cacheL1C1.Canonicalize(Perm);

  mu_cnt_req.Canonicalize(Perm);

  mu_cnt_resp.Canonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_threadIndexes.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_i_directoryL1C1.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_i_directoryL1C1.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_fwd.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_fwd.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_resp.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_resp.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_req.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_req.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_g_perm.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_g_perm.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_i_directoryL1C1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_i_directoryL1C1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_i_threadlist.Canonicalize(Perm);

  mu_i_cacheL1C1.Canonicalize(Perm);

  mu_cnt_req.Canonicalize(Perm);

  mu_cnt_resp.Canonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_threadIndexes.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_i_directoryL1C1.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_i_directoryL1C1.MultisetLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_fwd.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_fwd.MultisetSort();
  mu_resp.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_resp.MultisetSort();
  mu_req.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_req.MultisetSort();
  mu_g_perm.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_g_perm.MultisetSort();
  mu_i_directoryL1C1.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_i_directoryL1C1.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_fwd.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_fwd.MultisetSort();
      mu_resp.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_resp.MultisetSort();
      mu_req.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_req.MultisetSort();
      mu_g_perm.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_g_perm.MultisetSort();
      mu_i_directoryL1C1.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_i_directoryL1C1.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_i_threadlist.Canonicalize(Perm);

  mu_i_cacheL1C1.Canonicalize(Perm);

  mu_cnt_req.Canonicalize(Perm);

  mu_cnt_resp.Canonicalize(Perm);

  mu_cnt_fwd.Canonicalize(Perm);

  mu_i_threadIndexes.Canonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_i_directoryL1C1.SimpleLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_fwd.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_resp.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_req.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_fwd.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_fwd.MultisetSort();

  mu_resp.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_resp.MultisetSort();

  mu_req.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_req.MultisetSort();

  mu_g_perm.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_g_perm.MultisetSort();

  mu_i_directoryL1C1.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_i_directoryL1C1.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"
