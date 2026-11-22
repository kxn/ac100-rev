// func capwap_ac_session_hash_create @ 0058ff20 size=136

int capwap_ac_session_hash_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004080a0(capwap_ac_session_hash_obj,capwap_ac_session_hash_key,
                       capwap_ac_session_hash_cmp,param_1);
  if (((iVar1 == 0) && (capwap_err_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_ERROR]%32s():%4d Failed to create session hash.\n","capwap_ac_session_hash_create",
           0x13a);
  }
  return iVar1;
}

