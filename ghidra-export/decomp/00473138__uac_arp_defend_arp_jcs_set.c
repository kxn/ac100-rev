// func _uac_arp_defend_arp_jcs_set @ 00473138 size=1536

void _uac_arp_defend_arp_jcs_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  char *pcVar5;
  undefined8 uVar6;
  char local_2b8 [16];
  uint local_2a8;
  char acStack_2a4 [39];
  undefined1 local_27d;
  undefined1 auStack_27c [4];
  undefined1 auStack_278 [20];
  undefined1 auStack_264 [264];
  char *local_15c;
  char local_158 [20];
  undefined1 auStack_144 [6];
  char acStack_13e [255];
  undefined1 local_3f;
  undefined1 auStack_38 [28];
  
  local_2b8[0] = '\0';
  local_2b8[1] = '\0';
  local_2b8[2] = '\0';
  local_2b8[3] = '\0';
  local_2b8[4] = '\0';
  local_2b8[5] = '\0';
  local_2b8[6] = '\0';
  local_2b8[7] = '\0';
  local_2b8[8] = '\0';
  local_2b8[9] = '\0';
  local_2b8[10] = '\0';
  local_2b8[0xb] = '\0';
  local_2b8[0xc] = '\0';
  local_2b8[0xd] = '\0';
  local_2b8[0xe] = '\0';
  local_2b8[0xf] = '\0';
  local_2a8 = 0;
  memset(acStack_2a4,0,0x28);
  memset(&local_15c,0,0x120);
  memset(auStack_27c,0,0x120);
  memset(&local_15c,0,0x120);
  local_15c = (char *)0xffffffff;
  iVar1 = json_object_object_get(param_1,"arp_id");
  if (iVar1 == 0) {
    iVar1 = -1;
    if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
    goto LAB_00473230;
    __format = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
    uVar3 = 0x464;
    pcVar5 = "arp_id";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar6 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_arp_jcs_set",0x465);
        }
      }
    }
    iVar2 = arp_defend_db_arp_entry_get(iVar1,&local_15c);
    if (iVar2 != 0) {
      iVar2 = -1;
      iVar1 = iVar2;
      if ((arp_defend_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
      goto LAB_00473230;
      pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_arp_entry_get() failed.\n";
      uVar3 = 0x469;
LAB_004733ec:
      printf(pcVar5,"_uac_arp_defend_arp_jcs_set",uVar3);
      iVar1 = iVar2;
      goto LAB_00473230;
    }
    memcpy(auStack_27c,&local_15c,0x120);
    iVar2 = json_object_object_get(param_1,"description");
    if (iVar2 == 0) {
      iVar1 = -1;
      if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_00473230;
      __format = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
      uVar3 = 0x46f;
      pcVar5 = "description";
    }
    else {
      iVar4 = json_object_get_type(iVar2);
      if (iVar4 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar2);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_arp_defend_arp_jcs_set",0x470);
        }
        pcVar5 = "";
      }
      strncpy(acStack_13e,pcVar5,0xff);
      local_3f = 0;
      iVar2 = json_object_object_get(param_1,"mac");
      if (iVar2 == 0) {
        iVar1 = -1;
        if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_00473230;
        __format = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
        uVar3 = 0x473;
        pcVar5 = "mac";
      }
      else {
        iVar4 = json_object_get_type(iVar2);
        if (iVar4 == 6) {
          pcVar5 = (char *)json_object_get_string(iVar2);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_arp_defend_arp_jcs_set",0x474);
          }
          pcVar5 = "";
        }
        strncpy(local_2b8,pcVar5,0x13);
        local_2a8 = local_2a8 & 0xffffff00;
        iVar2 = arp_defend_str2mac(local_2b8,auStack_144);
        if (iVar2 == 0) {
          iVar2 = json_object_object_get(param_1,&DAT_00677c24);
          if (iVar2 == 0) {
            iVar1 = -1;
            if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_00473230;
            __format = "[ARP_DEFEND_ERROR]%s()/%d %s not found!\n";
            uVar3 = 0x47c;
            pcVar5 = "ip";
          }
          else {
            iVar4 = json_object_get_type(iVar2);
            if (iVar4 == 6) {
              pcVar5 = (char *)json_object_get_string(iVar2);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_arp_defend_arp_jcs_set",0x47d);
              }
              pcVar5 = "";
            }
            strncpy(acStack_2a4,pcVar5,0x27);
            local_27d = 0;
            arp_defend_str2ip(auStack_38,acStack_2a4);
            memcpy(local_158,auStack_38,0x14);
            if (local_158[0] == '\0') {
              iVar1 = -1;
              if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_00473230;
              __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_str2ip(%s) failed.\n";
              uVar3 = 0x481;
              pcVar5 = acStack_2a4;
            }
            else {
              iVar2 = memcmp(auStack_27c,&local_15c,0x120);
              if (iVar2 != 0) {
                arp_defend_print_arp_entry(&local_15c);
                iVar2 = arp_defend_db_arp_entry_set(&local_15c);
                if (iVar2 == 0) {
                  iVar2 = memcmp(auStack_278,local_158,0x14);
                  if ((iVar2 != 0) || (iVar2 = memcmp(auStack_264,auStack_144,6), iVar2 != 0)) {
                    arp_defend_db_arp_all_bindap_foreach(local_15c,_uac_arp_entry_modify_cb,0);
                  }
                  goto LAB_00473230;
                }
                iVar1 = iVar2;
                if ((arp_defend_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
                goto LAB_00473230;
                pcVar5 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_arp_entry_set() failed.\n";
                uVar3 = 0x490;
                goto LAB_004733ec;
              }
              iVar1 = -2;
              if ((arp_defend_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_00473230;
              __format = "[ARP_DEFEND_DEBUG]%s()/%d arp entry(%d) no change.\n";
              uVar3 = 0x487;
              pcVar5 = local_15c;
            }
          }
        }
        else {
          iVar1 = -1;
          if ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_00473230;
          __format = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_str2mac(%s) failed.\n";
          uVar3 = 0x477;
          pcVar5 = local_2b8;
        }
      }
    }
  }
  printf(__format,"_uac_arp_defend_arp_jcs_set",uVar3,pcVar5);
LAB_00473230:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"result",uVar3);
  if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_arp_jcs_set() finish, id=%d.\n",
           "_uac_arp_defend_arp_jcs_set",0x49e,iVar1);
  }
  return;
}

