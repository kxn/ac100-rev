// func _uac_arp_defend_arp_jcs_add @ 00473738 size=1084

void _uac_arp_defend_arp_jcs_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_190 [16];
  uint local_180;
  char acStack_17c [38];
  undefined1 local_156;
  int local_154;
  char local_150 [20];
  undefined1 auStack_13c [6];
  char acStack_136 [255];
  undefined1 local_37;
  undefined1 auStack_30 [24];
  
  memset(&local_154,0,0x120);
  local_190[0] = '\0';
  local_190[1] = '\0';
  local_190[2] = '\0';
  local_190[3] = '\0';
  local_190[4] = '\0';
  local_190[5] = '\0';
  local_190[6] = '\0';
  local_190[7] = '\0';
  local_190[8] = '\0';
  local_190[9] = '\0';
  local_190[10] = '\0';
  local_190[0xb] = '\0';
  local_190[0xc] = '\0';
  local_190[0xd] = '\0';
  local_190[0xe] = '\0';
  local_190[0xf] = '\0';
  local_180 = 0;
  memset(acStack_17c,0,0x27);
  local_154 = -1;
  iVar1 = json_object_object_get(param_1,"description");
  if (iVar1 == 0) {
    iVar1 = -1;
    if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_00473864;
    pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
    uVar3 = 0x4af;
    pcVar5 = "description";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_arp_defend_arp_jcs_add",0x4b0);
      }
      pcVar4 = "";
    }
    strncpy(acStack_136,pcVar4,0xff);
    local_37 = 0;
    iVar1 = json_object_object_get(param_1,"mac");
    if (iVar1 == 0) {
      iVar1 = -1;
      if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_00473864;
      pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
      uVar3 = 0x4b3;
      pcVar5 = "mac";
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar4 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_arp_jcs_add",0x4b4);
        }
        pcVar4 = "";
      }
      strncpy(local_190,pcVar4,0x13);
      local_180 = local_180 & 0xffffff00;
      iVar1 = arp_defend_str2mac(local_190,auStack_13c);
      if (iVar1 == 0) {
        iVar1 = json_object_object_get(param_1,&DAT_00677c24);
        if (iVar1 == 0) {
          iVar1 = -1;
          if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_00473864;
          pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
          uVar3 = 0x4bc;
          pcVar5 = "ip";
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 6) {
            pcVar4 = (char *)json_object_get_string(iVar1);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_uac_arp_defend_arp_jcs_add",0x4bd);
            }
            pcVar4 = "";
          }
          strncpy(acStack_17c,pcVar4,0x26);
          local_156 = 0;
          arp_defend_str2ip(auStack_30,acStack_17c);
          memcpy(local_150,auStack_30,0x14);
          if (local_150[0] != '\0') {
            iVar1 = arp_defend_db_arp_entry_add(&local_154);
            if (iVar1 == 0) {
              arp_defend_print_arp_entry(&local_154);
              iVar1 = local_154;
            }
            else {
              if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[ARP_DEFEND_DEBUG]%s()/%d arp_defend_db_arp_entry_add() failed.\n",
                       "_uac_arp_defend_arp_jcs_add",0x4c7);
              }
              uVar3 = json_object_new_int(1);
              json_object_object_add(param_2,"arp_list_data_exceed",uVar3);
            }
            goto LAB_00473864;
          }
          iVar1 = -1;
          if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_00473864;
          pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_str2ip(%s) failed.\n";
          uVar3 = 0x4c1;
          pcVar5 = acStack_17c;
        }
      }
      else {
        iVar1 = -1;
        if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_00473864;
        pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_str2mac(%s) failed.\n";
        uVar3 = 0x4b7;
        pcVar5 = local_190;
      }
    }
  }
  printf(pcVar4,"_uac_arp_defend_arp_jcs_add",uVar3,pcVar5);
  iVar1 = -1;
LAB_00473864:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"id",uVar3);
  if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_arp_jcs_add() finish, id=%d.\n",
           "_uac_arp_defend_arp_jcs_add",0x4d1,iVar1);
  }
  return;
}

