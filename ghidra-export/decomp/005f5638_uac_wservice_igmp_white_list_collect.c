// func uac_wservice_igmp_white_list_collect @ 005f5638 size=304

undefined4 uac_wservice_igmp_white_list_collect(int param_1,undefined1 *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    uVar4 = 0xffffffff;
    if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> input para is null\r\n",
             "uac_wservice_igmp_white_list_collect",0x1812);
    }
  }
  else {
    iVar3 = 0;
    uVar5 = 0;
    do {
      pcVar1 = (char *)(DAT_007cbf14 + iVar3);
      if ((*pcVar1 != '\0') && (pcVar1[0x1d] == '\x01')) {
        iVar2 = uVar5 * 0x1c;
        uVar5 = uVar5 + 1 & 0xff;
        iVar2 = param_1 + iVar2;
        *(char *)(iVar2 + 0x18) = pcVar1[0x1c];
        memcpy((void *)(iVar2 + 4),(void *)(DAT_007cbf14 + iVar3 + 8),0x14);
      }
      iVar3 = iVar3 + 0x20;
    } while (iVar3 != 0x400);
    uVar4 = 0;
    *param_2 = (char)uVar5;
  }
  return uVar4;
}

