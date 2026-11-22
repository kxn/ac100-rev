// func _uac_wsta_del_cb @ 00630f20 size=1084

undefined4 _uac_wsta_del_cb(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_30;
  void *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(&local_28), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> del wsta. ap_id[0x%08x], rd_id[%d].\r\n","_uac_wsta_del_cb",
           0x12d,*(undefined4 *)(param_1 + 0x20),(uint)*(byte *)(param_1 + 0x24));
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar1 = serv_wtp_address_arg_init(&local_28);
  if (iVar1 == -1) {
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(&local_28), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> serv_wtp_address_arg_init() fail.\r\n","_uac_wsta_del_cb",
             0x136);
    }
    serv_wtp_address_arg_destroy(&local_28);
    return 0xffffffff;
  }
  iVar1 = apmngr_db_get_addr_by_capacity(*(undefined2 *)(param_1 + 0x22),&local_28,0,1,0x15f0000,0);
  if (iVar1 == -1) {
    iVar1 = 0;
    if (g_wserv_error != 0) {
      iVar2 = is_target_debug_ap();
      uVar6 = 0xffffffff;
      if (iVar2 == 0) goto LAB_00630fb8;
      printf("<wserv>[error]%s(): %d  -> apmngr_db_get_addr_by_capacity() failed.ap_id=%d\r\n",
             "_uac_wsta_del_cb",0x13d,*(undefined4 *)(param_1 + 0x20));
    }
  }
  else {
    if (local_20 != 0) {
      iVar1 = cw_pkt_buf_create(0xfa);
      if (iVar1 == 0) {
        uVar6 = 0xffffffff;
        if ((g_wsta_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00630fb8;
        pcVar4 = "<wsta>[error]%s(): %d  -> no memory!\r\n";
        uVar5 = 0x14c;
      }
      else {
        local_30 = 0;
        local_2c = (void *)0x0;
        iVar2 = cw_parsed_pkt_create(0x19);
        if (iVar2 == 0) {
          if ((g_wsta_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            pcVar4 = "<wsta>[error]%s(): %d  -> no memory!\r\n";
            uVar6 = 0x9a;
LAB_0063126c:
            printf(pcVar4,"_uac_wsta_del_packet_create",uVar6);
          }
        }
        else {
          local_30 = CONCAT13(*(undefined1 *)(param_1 + 0x24),CONCAT12(6,local_30._2_2_));
          local_2c = (void *)FUN_00408450(6,0xa2);
          if (local_2c == (void *)0x0) {
            if ((g_wsta_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar4 = "<wsta>[error]%s(): %d  -> no memory!\r\n";
              uVar6 = 0xa5;
              goto LAB_0063126c;
            }
          }
          else {
            memcpy(local_2c,(void *)(param_1 + 0x68),6);
            iVar3 = cw_service_msg_add(iVar2,0x12,&local_30,0);
            if (iVar3 == 0) {
              iVar3 = capwap_packet_assemble(iVar1,iVar2);
              if (iVar3 != -1) {
                if (local_2c != (void *)0x0) {
                  FUN_00407df0();
                  local_2c = (void *)0x0;
                }
                cw_parsed_pkt_destroy(iVar2);
                iVar2 = serv_packet_send(&local_28,iVar1,0);
                uVar6 = 0;
                if (((iVar2 == 0) || (g_wsta_error == 0)) ||
                   (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00630fb8;
                pcVar4 = "<wsta>[error]%s(): %d  -> serv_packet_send() fail!\r\n";
                uVar5 = 0x159;
                goto LAB_00631144;
              }
              if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar4 = "<wserv>[error]%s(): %d  -> capwap_packet_assemble() fail!\r\n";
                uVar6 = 0xb4;
                goto LAB_0063126c;
              }
            }
            else if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              pcVar4 = "<wserv>[error]%s(): %d  -> cw_service_msg_add() fail!\r\n";
              uVar6 = 0xad;
              goto LAB_0063126c;
            }
          }
        }
        if (local_2c != (void *)0x0) {
          FUN_00407df0();
          local_2c = (void *)0x0;
        }
        if (iVar2 != 0) {
          cw_parsed_pkt_destroy(iVar2);
        }
        uVar6 = 0xffffffff;
        if (g_wsta_error == 0) goto LAB_00630fb8;
        uVar6 = 0xffffffff;
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) goto LAB_00630fb8;
        pcVar4 = "<wsta>[error]%s(): %d  -> _uac_wserv_packet_create() fail!\r\n";
        uVar5 = 0x153;
      }
LAB_00631144:
      printf(pcVar4,"_uac_wsta_del_cb",uVar5);
      goto LAB_00630fb8;
    }
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> no wtp need send wservice pakcet.\r\n","_uac_wsta_del_cb",
             0x144);
    }
  }
  iVar1 = 0;
  uVar6 = 0xffffffff;
LAB_00630fb8:
  serv_wtp_address_arg_destroy(&local_28);
  if (iVar1 != 0) {
    cw_pkt_buf_destroy(iVar1);
  }
  return uVar6;
}

