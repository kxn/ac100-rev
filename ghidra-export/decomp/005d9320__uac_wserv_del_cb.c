// func _uac_wserv_del_cb @ 005d9320 size=1048

undefined4 _uac_wserv_del_cb(uint *param_1,int param_2)

{
  undefined2 uVar3;
  int iVar1;
  int iVar2;
  uint uVar4;
  char *__format;
  undefined4 uVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  char local_240;
  char local_23f;
  byte local_23e;
  char local_23d;
  undefined4 local_23c;
  undefined4 local_238;
  int local_234;
  undefined4 local_230;
  undefined1 auStack_22c [283];
  int local_111;
  
  memset(auStack_22c,0,0x205);
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  uVar3 = rdmngr_db_generate_ap_id(*param_1);
  iVar1 = apmngr_db_capacity_support(uVar3,1,0x3f);
  if (param_2 == 0) {
    iVar2 = wserv_db_rd_get_wserv_id(*param_1,*(undefined1 *)(param_1 + 1));
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    iVar2 = wserv_db_get_entry_by_id(iVar2,auStack_22c);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    if ((iVar1 == 0) && (local_111 == 0)) {
      return 0xffffffff;
    }
  }
  else if ((iVar1 == 0) &&
          (uVar4 = param_2 + 0x11bU & 3, uVar8 = param_2 + 0x11eU & 3,
          (*(int *)((param_2 + 0x11bU) - uVar4) << uVar4 * 8 & -1 << (uVar8 + 1) * 8) == 0 &&
          *(uint *)((param_2 + 0x11eU) - uVar8) >> (3 - uVar8) * 8 == 0)) {
    return 0xffffffff;
  }
  if (g_wserv_debug == 0) {
    uVar4 = *param_1;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      uVar4 = *param_1;
    }
    else {
      printf("<wserv>[debug]%s(): %d  -> del wlan. rd_id[0x%08x], wlan_id[%d].\r\n",
             "_uac_wserv_del_cb",0x7fa,*param_1,(uint)*(byte *)(param_1 + 1));
      uVar4 = *param_1;
    }
  }
  local_23d = '\0';
  local_23e = 0;
  local_23f = -1;
  local_240 = -1;
  uVar4 = rdmngr_db_generate_ap_id(uVar4);
  uVar8 = *param_1;
  FUN_004082d0(DAT_007598e4,0xffffffff);
  iVar1 = _uac_wserv_packet_waiting_status_get_by_ap_id(uVar4,&local_23d);
  if (iVar1 == 0) {
    iVar1 = (uVar8 & 0xf) - 1;
    if (local_23d == '\0') {
      local_23c = 0;
      local_238 = 0;
      local_234 = 0;
      local_230 = 0;
      iVar2 = serv_wtp_address_arg_init(&local_23c);
      if (iVar2 == -1) {
        uVar7 = 0xffffffff;
        if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> serv_wtp_address_arg_init() fail.\r\n",
                 "_uac_wserv_packet_del_cb",0x72e);
        }
      }
      else {
        iVar2 = apmngr_db_get_addr_by_capacity(uVar4 & 0xffff,&local_23c,0,1,0x15f0000,0);
        if (iVar2 == -1) {
          uVar7 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            __format = 
            "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
            uVar5 = 0x734;
LAB_005d958c:
            uVar7 = 0xffffffff;
            printf(__format,"_uac_wserv_packet_del_cb",uVar5,uVar4);
          }
        }
        else {
          uVar7 = 0;
          if (local_234 != 0) {
            iVar2 = serv_user_defined_packet_send(&local_23c,_uac_wserv_packet_send_callback);
            if (iVar2 == 0) {
              _uac_wserv_packet_waiting_status_set_by_ap_id(uVar4,1);
              _uac_wserv_packet_type_get_by_wlan_id
                        (uVar4,iVar1,*(char *)(param_1 + 1) + -1,&local_23e);
              _uac_wserv_packet_type_set_by_wlan_id
                        (uVar4,iVar1,*(char *)(param_1 + 1) + -1,local_23e & 0xf0 | 2);
              _uac_wserv_packet_cur_id_set_by_ap_id
                        (uVar4,iVar1,(int)(char)(*(char *)(param_1 + 1) + -1));
            }
            else {
              uVar7 = 0xffffffff;
              if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                __format = 
                "<wserv>[warning]%s(): %d  -> serv_user_defined_packet_send() failed.ap_id=%d\r\n";
                uVar5 = 0x740;
                goto LAB_005d958c;
              }
            }
          }
        }
      }
      serv_wtp_address_arg_destroy(&local_23c);
    }
    else {
      iVar2 = _uac_wserv_packet_type_get_by_wlan_id
                        (uVar4,iVar1,*(char *)(param_1 + 1) + -1,&local_23e);
      if (iVar2 != 0) goto LAB_005d9728;
      if (local_23e >> 4 == 1) {
        _uac_wserv_packet_type_set_by_wlan_id(uVar4,iVar1,*(char *)(param_1 + 1) + -1,0x12);
        iVar2 = _uac_wserv_packet_cur_id_get_by_ap_id(uVar4,&local_23f,&local_240);
        if (iVar2 != 0) goto LAB_005d9728;
        iVar2 = (int)local_23f;
        if (iVar2 == -1) {
LAB_005d9658:
          cVar6 = *(char *)(param_1 + 1);
        }
        else if (local_240 == -1) {
          cVar6 = *(char *)(param_1 + 1);
        }
        else {
          if (iVar2 <= iVar1) {
            uVar7 = 0;
            if ((iVar1 != iVar2) || ((int)local_240 <= (int)(*(byte *)(param_1 + 1) - 1)))
            goto LAB_005d9454;
            goto LAB_005d9658;
          }
          cVar6 = *(char *)(param_1 + 1);
        }
        _uac_wserv_packet_cur_id_set_by_ap_id(uVar4,iVar1,(int)(char)(cVar6 + -1));
        uVar7 = 0;
      }
      else {
        _uac_wserv_packet_type_set_by_wlan_id
                  (uVar4,iVar1,*(char *)(param_1 + 1) + -1,(uint)(local_23e >> 4) << 4);
        _uac_wserv_packet_next_cur_id_update_by_ap_id(uVar4);
        uVar7 = 0;
      }
    }
LAB_005d9454:
    FUN_00407f30(DAT_007598e4);
  }
  else {
LAB_005d9728:
    uVar7 = 0xffffffff;
    FUN_00407f30(DAT_007598e4);
  }
  return uVar7;
}

