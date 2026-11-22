// func cw_priv_ap_firmware_id_parse @ 005a4d54 size=416

undefined4 cw_priv_ap_firmware_id_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  void *__s;
  int iVar4;
  undefined4 uVar5;
  void *__s_00;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x18,0x79);
  if (__s == (void *)0x0) {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_firmware_id_parse",0x7c);
    }
  }
  else {
    memset(__s,0,0x18);
    cw_protocol_retrieve_bytes(param_1,__s,0x10);
    iVar4 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 0x10) = (char)iVar4;
    if (iVar4 == 0) {
      uVar3 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(iVar4 << 4,0x87);
      *(void **)((int)__s + 0x14) = __s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d malloc bl firmware list failed\n",
                 "cw_priv_ap_firmware_id_parse",0x8a);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
      memset(__s_00,0,(uint)*(byte *)((int)__s + 0x10) << 4);
      bVar1 = *(byte *)((int)__s + 0x10);
      for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) {
        cw_protocol_retrieve_bytes(param_1,*(int *)((int)__s + 0x14) + iVar4 * 0x10,0x10);
        bVar1 = *(byte *)((int)__s + 0x10);
      }
      uVar3 = *(ushort *)(param_2 + 0xe);
    }
    *(void **)(param_2 + 0x10) = __s;
    uVar5 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 == (uint)uVar3) {
      uVar5 = 0;
    }
  }
  return uVar5;
}

