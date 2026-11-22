// func uac_wserv_update_aps_md5 @ 005dd600 size=8

void uac_wserv_update_aps_md5(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  char acStack_318 [4];
  undefined4 uStack_314;
  undefined4 uStack_310;
  int iStack_30c;
  undefined4 uStack_308;
  undefined1 auStack_300 [728];
  
  iVar7 = 0;
  acStack_318[0] = '\0';
  uStack_314 = 0;
  uStack_310 = 0;
  iStack_30c = 0;
  uStack_308 = 0;
  memset(auStack_300,0,0x2d8);
LAB_005d7f7c:
  while( true ) {
    iVar1 = apmngr_db_get_ap_max();
    if ((iVar1 <= iVar7) || (param_2 < 1)) {
      return;
    }
    iVar1 = iVar7 >> 5;
    piVar5 = (int *)(param_1 + iVar1 * 4);
    if (*piVar5 != 0) break;
    iVar7 = iVar7 + 0x20;
  }
  if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> apv[%d]=0x%08x\r\n","_uac_wserv_update_aps_md5",0x939,iVar1,
           *piVar5);
  }
  uVar4 = iVar1 << 5;
  uVar6 = 0;
  iVar1 = *piVar5;
  do {
    if ((iVar1 >> (uVar6 & 0x1f) & 1U) != 0) {
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> update ap[%d]\'s md5\r\n","_uac_wserv_update_aps_md5",
               0x93f,uVar4);
      }
      iVar1 = apmngr_db_entry_get_by_id(uVar4 & 0xffff,auStack_300);
      if (iVar1 == 0) {
        iVar1 = apmngr_checksum_update(auStack_300,0);
        if (iVar1 != 0) {
          if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> update md5 failed.\r\n","_uac_wserv_update_aps_md5"
                   ,0x944);
          }
          goto LAB_005d8018;
        }
        FUN_004082d0(DAT_007598e4,0xffffffff);
        _uac_wserv_packet_waiting_status_get_by_ap_id(uVar4,acStack_318);
        if (acStack_318[0] == '\x01') {
          _uac_wserv_packet_md5_type_set_by_ap_id(uVar4,1);
        }
        else {
          uStack_314 = 0;
          uStack_310 = 0;
          iStack_30c = 0;
          uStack_308 = 0;
          iVar1 = serv_wtp_address_arg_init(&uStack_314);
          if (iVar1 == -1) {
            if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("<wserv>[warning]%s(): %d  -> serv_wtp_address_arg_init() fail.\r\n",
                     "_uac_wserv_update_aps_md5",0x953);
            }
          }
          else {
            iVar1 = apmngr_db_get_addr_by_capacity(uVar4 & 0xffff,&uStack_314,0,1,0x15f0000,0);
            if (iVar1 == -1) {
              if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                __format = 
                "<wserv>[warning]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n";
                uVar3 = 0x958;
LAB_005d8208:
                printf(__format,"_uac_wserv_update_aps_md5",uVar3,uVar4);
              }
            }
            else if (iStack_30c != 0) {
              _uac_wserv_packet_md5_type_set_by_ap_id(uVar4,1);
              iVar1 = serv_user_defined_packet_send(&uStack_314,_uac_wserv_packet_send_callback);
              if ((iVar1 != 0) && (g_wserv_warning != 0)) {
                iVar1 = is_target_debug_ap();
                uVar3 = 0x962;
                if (iVar1 != 0) {
                  __format = 
                  "<wserv>[warning]%s(): %d  -> serv_user_defined_packet_send() failed.ap_id=%d\r\n"
                  ;
                  goto LAB_005d8208;
                }
              }
            }
          }
          serv_wtp_address_arg_destroy(&uStack_314);
        }
        FUN_00407f30(DAT_007598e4);
      }
      else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail.ap_id=%d\r\n",
               "_uac_wserv_update_aps_md5",0x96c,uVar4);
      }
      param_2 = param_2 + -1;
    }
LAB_005d8018:
    uVar6 = uVar6 + 1;
    uVar4 = uVar4 + 1;
    if ((uVar6 == 0x20) || (param_2 < 1)) break;
    iVar1 = *piVar5;
  } while( true );
  iVar7 = iVar7 + 0x20;
  goto LAB_005d7f7c;
}

