// func capwap_ac_session_hash_obj @ 0058fa78 size=76

undefined4 capwap_ac_session_hash_obj(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = capwap_ac_session_hash_key(param_1 + 0x2c);
    return uVar1;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_ac_session_hash_obj",0x6a,"session");
  return 0;
}

