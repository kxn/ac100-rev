// func mac_auth_wsta_callback_sta_check @ 00451380 size=2032

undefined4 mac_auth_wsta_callback_sta_check(byte *param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  byte *__src;
  undefined4 uVar6;
  undefined4 uVar7;
  uint in_stack_fffffa70;
  int local_570;
  byte local_56c;
  byte local_56b;
  byte local_56a;
  byte local_569;
  byte local_568;
  byte local_567;
  char local_564 [104];
  undefined1 auStack_4fc [46];
  ushort local_4ce;
  undefined1 auStack_47c [396];
  undefined1 auStack_2f0 [20];
  uint local_2dc;
  byte local_2a8;
  byte local_2a7;
  byte local_2a6;
  byte local_2a5;
  byte local_2a4;
  byte local_2a3;
  undefined1 auStack_2a2 [542];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  memset(auStack_47c,0,0x188);
  local_570 = 0;
  local_564[0x14] = '\0';
  local_564[0x15] = '\0';
  local_564[0x16] = '\0';
  local_564[0x17] = '\0';
  local_564[0x18] = '\0';
  local_564[0x19] = '\0';
  local_564[0x1a] = '\0';
  local_564[0x1b] = '\0';
  local_564[0x1c] = '\0';
  local_564[0x1d] = '\0';
  local_564[0x1e] = '\0';
  local_564[0x1f] = '\0';
  local_564[0x20] = '\0';
  local_564[0x21] = '\0';
  local_564[0x22] = '\0';
  local_564[0x23] = '\0';
  local_564[0x24] = '\0';
  local_564[0x25] = '\0';
  local_564[0x26] = '\0';
  local_564[0x27] = '\0';
  local_564[0] = '\0';
  local_564[1] = '\0';
  local_564[2] = '\0';
  local_564[3] = '\0';
  local_564[4] = '\0';
  local_564[5] = '\0';
  local_564[6] = '\0';
  local_564[7] = '\0';
  local_564[8] = '\0';
  local_564[9] = '\0';
  local_564[10] = '\0';
  local_564[0xb] = '\0';
  local_564[0xc] = '\0';
  local_564[0xd] = '\0';
  local_564[0xe] = '\0';
  local_564[0xf] = '\0';
  local_564[0x10] = '\0';
  local_564[0x11] = '\0';
  local_564[0x12] = '\0';
  local_564[0x13] = '\0';
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_4fc,0,0x80);
  if (param_1 == (byte *)0x0) {
    uVar7 = 0x25;
    if (macauth_err_switch == 0) {
      return 0x25;
    }
    pcVar5 = "[MACAUTH_ERROR]%s()/%d Invalid params.\n";
    uVar6 = 0x39;
  }
  else {
    __src = param_1 + 0xd;
    if (param_1[0xb] != 1) {
      __src = param_1 + 0xc;
    }
    memcpy(&local_56c,__src,6);
    if (macauth_debug_switch == 0) {
      uVar1 = *(undefined2 *)(param_1 + 6);
    }
    else {
      in_stack_fffffa70 = (uint)local_569;
      printf("[MACAUTH_DEBUG]%s()/%d mac auth:%02x:%02x:%02x:%02x:%02x:%02x \n",
             "mac_auth_wsta_callback_sta_check",0x44,(uint)local_56c,(uint)local_56b,(uint)local_56a
             ,in_stack_fffffa70,(uint)local_568,(uint)local_567);
      uVar1 = *(undefined2 *)(param_1 + 6);
    }
    iVar3 = apmngr_db_entry_get_by_id(uVar1,auStack_2f0);
    if (iVar3 == -1) {
      uVar7 = 0x25;
      if (macauth_err_switch == 0) {
        return 0x25;
      }
      pcVar5 = "[MACAUTH_ERROR]%s()/%d get apentry by id failed.\n";
      uVar6 = 0x48;
    }
    else if (((((local_2dc < 2) || (local_2dc == 3)) || (local_2dc == 2)) ||
             ((local_2dc == 4 || (local_2dc == 8)))) || (local_2dc == 6)) {
      if (g_macauth_mode == 1) {
        uVar2 = *(ushort *)(param_1 + 8);
        iVar3 = wsta_db_get_entry_by_mac(&local_56c,auStack_4fc);
        if (iVar3 == 0) {
          uVar2 = local_4ce;
        }
        uVar4 = (uint)uVar2;
        if (macauth_debug_switch != 0) {
          printf("[MACAUTH_DEBUG]%s()/%d VLAN is %d\n","mac_auth_wsta_callback_sta_check",0x59,uVar4
                );
        }
        iVar3 = mac_auth_db_group_entry_get_by_vid(uVar4,auStack_47c);
        if (iVar3 != 0) {
          if (macauth_debug_switch == 0) {
            return 0;
          }
          pcVar5 = "[MACAUTH_DEBUG]%s()/%d MAC auth is not enabled in vlan(%d).\n";
          uVar7 = 0x5c;
          goto LAB_0045151c;
        }
        if (param_1[0xb] == 0) {
          iVar3 = mac_auth_db_mac_get_vlan_bind_status(&local_56c,uVar4,auStack_47c,&local_570);
        }
        else {
          iVar3 = mac_auth_db_mlo_mac_get_bind_status
                            (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                             *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                             *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                             CONCAT13(param_1[0x24],(int3)in_stack_fffffa70),auStack_47c,&local_570)
          ;
        }
        if (iVar3 == 0) goto LAB_00451798;
        if (param_1[10] == 0) {
          snprintf(local_564 + 0x14,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a8,
                   (uint)local_2a7,(uint)local_2a6,(uint)local_2a5,(uint)local_2a4,(uint)local_2a3);
          snprintf(local_564,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_56c,(uint)local_56b,
                   (uint)local_56a,(uint)local_569,(uint)local_568,(uint)local_567);
          memset(local_564 + 0x28,0,0x40);
          FUN_00408190(local_84,local_80,local_7c,local_78,local_74,local_564 + 0x28,0x40,"---");
          loggerk_reg(0x58,0x3909,1,auStack_2a2,1,local_564 + 0x28,1,local_564 + 0x14,1,local_564,0)
          ;
        }
        uVar7 = 0x25;
        if (macauth_debug_switch == 0) {
          return 0x25;
        }
        pcVar5 = "[MACAUTH_DEBUG]%s()/%d normal_mac_get_vlan_bind_status() failed.\n";
        uVar6 = 0x7a;
      }
      else {
        uVar4 = uac_wservice_get_wserv_id(*(undefined4 *)(param_1 + 4),*param_1,param_1[1]);
        if (uVar4 == 0xffffffff) {
          if (macauth_debug_switch == 0) {
            return 0;
          }
          printf("[MACAUTH_DEBUG]%s()/%d wservice not found for [%d-%d-%d].\n",
                 "mac_auth_wsta_callback_sta_check",0x82,*(undefined4 *)(param_1 + 4),(uint)*param_1
                 ,(uint)param_1[1]);
          return 0;
        }
        iVar3 = mac_auth_db_group_entry_get_by_ssid(uVar4,auStack_47c);
        if (iVar3 != 0) {
          if (macauth_debug_switch == 0) {
            return 0;
          }
          pcVar5 = "[MACAUTH_DEBUG]%s()/%d MAC auth is not enabled in ssid(%d).\n";
          uVar7 = 0x87;
LAB_0045151c:
          printf(pcVar5,"mac_auth_wsta_callback_sta_check",uVar7,uVar4);
          return 0;
        }
        if (param_1[0xb] == 0) {
          iVar3 = mac_auth_db_mac_get_ssid_bind_status
                            (&local_56c,uVar4 & 0xffff,auStack_47c,&local_570);
        }
        else {
          iVar3 = mac_auth_db_mlo_mac_get_bind_status
                            (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                             *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                             *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                             CONCAT13(param_1[0x24],(int3)in_stack_fffffa70),auStack_47c,&local_570)
          ;
        }
        if (iVar3 == 0) {
LAB_00451798:
          uVar7 = 0;
          if (((local_570 == 0) && (uVar7 = 0x25, param_1[10] == 0)) &&
             (iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 6),auStack_2f0),
             iVar3 == 0)) {
            snprintf(local_564 + 0x14,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a8,
                     (uint)local_2a7,(uint)local_2a6,(uint)local_2a5,(uint)local_2a4,(uint)local_2a3
                    );
            snprintf(local_564,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_56c,(uint)local_56b,
                     (uint)local_56a,(uint)local_569,(uint)local_568,(uint)local_567);
            memset(local_564 + 0x28,0,0x40);
            FUN_00408190(local_84,local_80,local_7c,local_78,local_74,local_564 + 0x28,0x40,"---");
            loggerk_reg(0x58,0x3909,1,auStack_2a2,1,local_564 + 0x28,1,local_564 + 0x14,1,local_564,
                        0);
          }
          if (macauth_debug_switch == 0) {
            return uVar7;
          }
          if (local_570 == 0) {
            pcVar5 = "forbid";
          }
          else {
            pcVar5 = "passed";
          }
          printf("[MACAUTH_DEBUG]%s()/%d MACAUTH: STA [%02X:%02X:%02X:%02X:%02X:%02X] %s\n",
                 "mac_auth_wsta_callback_sta_check",0xc0,(uint)local_56c,(uint)local_56b,
                 (uint)local_56a,(uint)local_569,(uint)local_568,(uint)local_567,pcVar5);
          return uVar7;
        }
        if (param_1[10] == 0) {
          snprintf(local_564 + 0x14,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a8,
                   (uint)local_2a7,(uint)local_2a6,(uint)local_2a5,(uint)local_2a4,(uint)local_2a3);
          snprintf(local_564,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_56c,(uint)local_56b,
                   (uint)local_56a,(uint)local_569,(uint)local_568,(uint)local_567);
          memset(local_564 + 0x28,0,0x40);
          FUN_00408190(local_84,local_80,local_7c,local_78,local_74,local_564 + 0x28,0x40,"---");
          loggerk_reg(0x58,0x3909,1,auStack_2a2,1,local_564 + 0x28,1,local_564 + 0x14,1,local_564,0)
          ;
        }
        uVar7 = 0x25;
        if (macauth_debug_switch == 0) {
          return 0x25;
        }
        pcVar5 = "[MACAUTH_DEBUG]%s()/%d mac_auth_db_mac_get_ssid_bind_status() failed.\n";
        uVar6 = 0xa3;
      }
    }
    else {
      uVar7 = 0;
      if (macauth_debug_switch == 0) {
        return 0;
      }
      pcVar5 = "[MACAUTH_DEBUG]%s()/%d Non-AP no need to check.\n";
      uVar6 = 0x4d;
    }
  }
  printf(pcVar5,"mac_auth_wsta_callback_sta_check",uVar6);
  return uVar7;
}

