// func _uac_rdmngr_ap_name_cmp @ 006243a0 size=376

bool _uac_rdmngr_ap_name_cmp(undefined4 *param_1,char *param_2)

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
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_ap_name_cmp begins, search name:%s\n",
           "_uac_rdmngr_ap_name_cmp",0x2e8,param_2);
  }
  bVar6 = true;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (char *)0x0)) {
    uVar5 = rdmngr_db_generate_ap_id(*param_1);
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
    pcVar4 = strstr((char *)abStack_3f8,param_2);
    bVar6 = pcVar4 == (char *)0x0;
    if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_ap_name_cmp finish.\n","_uac_rdmngr_ap_name_cmp",
             0x2f5);
    }
  }
  return bVar6;
}

