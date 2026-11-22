// func FUN_00478638 @ 00478638 size=536

int FUN_00478638(uint *param_1,uint param_2,char *param_3)

{
  int iVar1;
  char cVar3;
  size_t sVar2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char local_30 [16];
  
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = '\0';
  local_30[5] = '\0';
  local_30[6] = '\0';
  local_30[7] = '\0';
  local_30[8] = '\0';
  local_30[9] = '\0';
  if ((param_1 == (uint *)0x0) || (param_3 == (char *)0x0)) {
    iVar5 = -1;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","_arp_defend_arpids2str",0xdd,
           "id_list && id_str");
  }
  else if (DAT_007670f0 < param_2) {
    iVar5 = -1;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid list_len[%d]!\n","_arp_defend_arpids2str",0xe1,
             param_2);
    }
  }
  else {
    uVar6 = 0;
    memset(param_3,0,0x401);
    iVar5 = 0;
    if (param_2 != 0) {
      uVar4 = *param_1;
      while( true ) {
        if ((-1 < (int)uVar4) && (uVar4 < g_arp_defend_profile)) {
          snprintf(local_30,10,"%d,");
          strcat(param_3,local_30);
          iVar5 = iVar5 + 1;
        }
        uVar6 = uVar6 + 1;
        param_1 = param_1 + 1;
        if (uVar6 == param_2) break;
        uVar4 = *param_1;
      }
    }
    if (arp_defend_debug_switch == 0) {
      cVar3 = *param_3;
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        cVar3 = *param_3;
      }
      else {
        sVar2 = strlen(param_3);
        printf("[ARP_DEFEND_DEBUG]%s()/%d strlen(id_str) is %d.\n","_arp_defend_arpids2str",0xf9,
               sVar2);
        cVar3 = *param_3;
      }
    }
    if (cVar3 != '\0') {
      sVar2 = strlen(param_3);
      param_3[sVar2 - 1] = '\0';
    }
    if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_DEBUG]%s()/%d id_str: %s, id_num: %d\n","_arp_defend_arpids2str",0xfe,
             param_3,iVar5);
    }
  }
  return iVar5;
}

