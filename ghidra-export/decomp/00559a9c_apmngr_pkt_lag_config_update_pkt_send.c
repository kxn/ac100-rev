// func apmngr_pkt_lag_config_update_pkt_send @ 00559a9c size=812

int apmngr_pkt_lag_config_update_pkt_send
              (uint param_1,undefined1 param_2,undefined1 param_3,char param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  
  param_1 = param_1 & 0xffff;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (param_4 == '\0') {
    param_4 = '\x01';
    iVar1 = cw_protocol_clone("0",1);
  }
  else {
    iVar1 = cw_protocol_clone(param_5,param_4);
  }
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  iVar2 = serv_wtp_address_arg_init(&local_30);
  if (iVar2 == -1) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(&local_30), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Failed to serv_wtp_address_arg_init()!\n",
             "apmngr_pkt_lag_config_update_pkt_send",0x91a);
    }
    serv_wtp_address_arg_destroy(&local_30);
    return -1;
  }
  iVar2 = apmngr_db_get_addr_by_capacity(param_1,&local_30,1,1,0x15f0000,1,0x47);
  if (iVar2 == 0) {
    if (local_28 == 0) {
      iVar2 = 0;
      if ((apmngr_debug_switch == '\0') || (iVar5 = is_target_debug_ap(), iVar5 == 0)) {
        iVar5 = 0;
      }
      else {
        printf("[APMNGR_DEBUG]%s()/%d <-------------Num of APs is 0, no need to send packet.\n",
               "apmngr_pkt_lag_config_update_pkt_send",0x92b);
        iVar5 = 0;
      }
    }
    else {
      if ((apmngr_debug_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d Num of APs to be notified: %d.\n",
               "apmngr_pkt_lag_config_update_pkt_send",0x932,local_28);
      }
      iVar2 = cw_pkt_buf_create(0xfa);
      if (iVar2 == 0) {
        iVar5 = -1;
        if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[APMNGR_ERROR]%s()/%d no memory!\n","apmngr_pkt_lag_config_update_pkt_send",0x93b)
          ;
        }
      }
      else {
        iVar5 = _apmngr_pkt_lag_config_update_pkt_create
                          (param_1,iVar2,param_2,param_3,param_4,iVar1);
        if (iVar5 == 0) {
          iVar3 = serv_packet_send(&local_30,iVar2,1);
          if (iVar3 == 0) {
            if ((apmngr_debug_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_00559b98;
            __format = "[APMNGR_DEBUG]%s()/%d <-------------succeed to send packet to ap_id[%d].\n";
            uVar4 = 0x94b;
          }
          else {
            if ((apmngr_err_switch == '\0') || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_00559b98;
            __format = "[APMNGR_ERROR]%s()/%d Failed to send packt to ap_id[%d]!\n";
            uVar4 = 0x947;
          }
          printf(__format,"apmngr_pkt_lag_config_update_pkt_send",uVar4,param_1);
        }
      }
    }
  }
  else {
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d can not supoort new ap trunk .\n",
             "apmngr_pkt_lag_config_update_pkt_send",0x924);
    }
    iVar2 = 0;
    iVar5 = -1;
  }
LAB_00559b98:
  serv_wtp_address_arg_destroy(&local_30);
  if (iVar2 != 0) {
    cw_pkt_buf_destroy(iVar2);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return iVar5;
}

