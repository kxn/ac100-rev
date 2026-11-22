// func _uac_wserv_for_collect_igmp_switch_cb @ 005d7b64 size=308

undefined4 _uac_wserv_for_collect_igmp_switch_cb(char *param_1,int param_2,undefined4 *param_3)

{
  void *__s;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  pcVar2 = param_1;
  if (g_wserv_debug != 0) {
    iVar1 = is_target_debug_ap();
    pcVar2 = " ip list \r\n";
    if (iVar1 != 0) {
      printf("<wserv>[debug]%s(): %d  -> wserv_id = %d\r\n","_uac_wserv_for_collect_igmp_switch_cb",
             0x12d3,*(undefined4 *)(param_1 + 0x80));
      pcVar2 = (char *)0x14;
    }
  }
  if (param_2 == 0) {
    uVar3 = 0xffffffff;
    if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(pcVar2), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> priv is null\r\n","_uac_wserv_for_collect_igmp_switch_cb",
             0x12d6);
    }
  }
  else {
    uVar3 = 0xffffffff;
    __s = (void *)FUN_00408450(0x14,0x12da);
    if (__s != (void *)0x0) {
      memset(__s,0,0x14);
      uVar3 = 0;
      *(byte *)((int)__s + 0xc) = ((byte)*param_3 & 0xf) - 1;
      *(ushort *)((int)__s + 0xe) = (ushort)*(byte *)(param_3 + 1);
      *(char *)((int)__s + 0x10) = param_1[0x203];
      *(char *)((int)__s + 0x11) = param_1[0x204];
      FUN_004086b0(param_2 + 4,__s);
    }
  }
  return uVar3;
}

