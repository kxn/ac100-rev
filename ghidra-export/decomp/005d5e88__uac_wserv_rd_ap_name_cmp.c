// func _uac_wserv_rd_ap_name_cmp @ 005d5e88 size=368

bool _uac_wserv_rd_ap_name_cmp(undefined4 param_1,undefined4 param_2,char *param_3)

{
  undefined2 uVar5;
  int iVar1;
  size_t sVar2;
  byte *pbVar3;
  char *pcVar4;
  bool bVar6;
  byte abStack_3f8 [264];
  undefined1 auStack_2f0 [78];
  undefined1 auStack_2a2 [654];
  
  memset(abStack_3f8,0,0x101);
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_ap_name_cmp begins, search name:%s\r\n",
           "_uac_wserv_rd_ap_name_cmp",0x20a,param_3);
  }
  bVar6 = true;
  if (param_3 != (char *)0x0) {
    uVar5 = rdmngr_db_generate_ap_id(param_2);
    memset(auStack_2f0,0,0x2d8);
    iVar1 = apmngr_db_entry_get_by_id(uVar5,auStack_2f0);
    if (iVar1 == 0) {
      snprintf((char *)abStack_3f8,0x100,"%s",auStack_2a2);
    }
    sVar2 = strlen((char *)abStack_3f8);
    pbVar3 = abStack_3f8 + sVar2;
    while (pbVar3 = pbVar3 + -1, abStack_3f8 <= pbVar3) {
      if ((byte)(*pbVar3 + 0x9f) < 0x1a) {
        *pbVar3 = *pbVar3 & 0xdf;
      }
    }
    pcVar4 = strstr((char *)abStack_3f8,param_3);
    bVar6 = pcVar4 == (char *)0x0;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> _uac_wserv_rd_ap_name_cmp finish.\r\n",
             "_uac_wserv_rd_ap_name_cmp",0x217);
    }
  }
  return bVar6;
}

