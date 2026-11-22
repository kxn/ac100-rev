// func cw_priv_apdb_info_parse @ 005ab25c size=308

undefined4 cw_priv_apdb_info_parse(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  short *__s;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (short *)FUN_00408450(8,0x99);
  if (__s == (short *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_apdb_info_parse",0x9c);
    }
  }
  else {
    memset(__s,0,8);
    sVar2 = *(short *)(param_2 + 0xe);
    *__s = sVar2;
    if (sVar2 != 0) {
      iVar4 = cw_protocol_retrieve_raw_bytes(param_1);
      *(int *)(__s + 2) = iVar4;
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to parse portal syn\n","cw_priv_apdb_info_parse",0xa8)
          ;
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(short **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

