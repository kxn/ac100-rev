// func _wsta_roam_pkt_pmk_request @ 00486d74 size=1096

undefined4
_wsta_roam_pkt_pmk_request(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  char *__src;
  undefined4 local_458;
  undefined4 local_454;
  int local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined1 auStack_430 [8];
  int local_428;
  undefined4 local_424;
  undefined1 auStack_420 [6];
  undefined1 auStack_41a [32];
  undefined1 auStack_3fa [18];
  undefined4 local_3e8;
  undefined1 local_3e4;
  undefined1 local_3e3;
  undefined1 auStack_3af [32];
  undefined1 auStack_38f [19];
  undefined1 auStack_37c [53];
  char local_347;
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  uint local_a0;
  
  local_444 = 0;
  local_440 = 0;
  local_43c = 0;
  local_438 = 0;
  local_434 = 0;
  memset(&local_3e4,0,0x68);
  memset(auStack_2f8,0,0x2d8);
  memset(auStack_430,0,0x4c);
  memset(auStack_37c,0,0x80);
  local_458 = 0;
  local_454 = 0;
  local_450 = 0;
  local_44c = 0;
  local_448 = 0;
  iVar2 = apmngr_db_entry_get_by_mac(param_3,auStack_2f8);
  if (iVar2 == 0) {
    memcpy(&local_3e4,param_1,0x68);
    cVar1 = *param_1;
    if (cVar1 != '\x01') {
      if (cVar1 == '\0') {
        l_wsta_roam_pkt_info_stat = l_wsta_roam_pkt_info_stat + 1;
        local_428 = uac_wservice_get_wserv_id(local_2e8,param_1[2],param_1[3]);
        if (local_428 == -1) {
          return 0;
        }
        local_424 = *(undefined4 *)(param_1 + 4);
        memcpy(auStack_420,param_1 + 0x29,6);
        memcpy(auStack_41a,param_1 + 0x35,0x20);
        memcpy(auStack_3fa,param_1 + 0x55,0x10);
        local_3e8 = 0;
        wsta_roam_db_pmk_add(auStack_430);
        DAT_007675cc = DAT_007675cc + 1;
        return 0;
      }
      if (cVar1 != '\x03') {
        DAT_007675e0 = DAT_007675e0 + 1;
        return 0;
      }
    }
    if (((local_a0 & 4) == 0) && (cVar1 == '\x03')) {
      return 0;
    }
    __src = param_1 + 0x29;
    DAT_007675d0 = DAT_007675d0 + 1;
    local_3e4 = 2;
    iVar2 = wsta_roam_db_pmk_get_by_mac(__src,auStack_430);
    if (iVar2 == -1) {
      if (wsta_roam_warning_switch == '\0') {
        local_3e3 = 1;
      }
      else {
        printf("[WSTA_ROAM_WARNING]%s()/%d Can not find roam entry of mac[%02x-%02x-%02x-%02x-%02x-%02x]\n"
               ,"_wsta_roam_pkt_pmk_request",0x154,(uint)(byte)param_1[0x29],
               (uint)(byte)param_1[0x2a],(uint)(byte)param_1[0x2b],(uint)(byte)param_1[0x2c],
               (uint)(byte)param_1[0x2d],(uint)(byte)param_1[0x2e]);
        local_3e3 = 1;
      }
    }
    else {
      iVar2 = uac_wservice_get_wserv_id(local_2e8,param_1[2],param_1[3]);
      if (iVar2 == -1) {
        if (wsta_roam_warning_switch == '\0') {
          local_3e3 = 2;
        }
        else {
          printf("[WSTA_ROAM_WARNING]%s()/%d Can not find new wserv entry of [ap_id:%d rd_id:%d wlan_id:%d]\n"
                 ,"_wsta_roam_pkt_pmk_request",0x15d,(uint)local_2e8,(uint)(byte)param_1[2],
                 (uint)(byte)param_1[3]);
          local_3e3 = 2;
        }
      }
      else {
        if (iVar2 == local_428) {
          DAT_007675d4 = DAT_007675d4 + 1;
          if (*param_1 == '\x03') {
            local_458 = CONCAT13(param_1[2],CONCAT12(param_1[3],local_458._2_2_));
            memcpy((void *)((int)&local_458 + 2),__src,6);
            iVar2 = wsta_db_get_entry_by_mac(__src,auStack_37c);
            if (iVar2 == 0) {
              local_450 = (int)local_347;
            }
            uac_wstation_assoc(local_2e8,local_458._0_1_,local_458._1_1_,(int)&local_458 + 2,
                               local_450,0,0,0,0);
          }
          local_3e3 = 0;
          memcpy(auStack_3af,auStack_41a,0x20);
          memcpy(auStack_38f,auStack_3fa,0x10);
          goto LAB_00486e28;
        }
        if (wsta_roam_warning_switch == '\0') {
          local_3e3 = 1;
        }
        else {
          printf("[WSTA_ROAM_WARNING]%s()/%d wserv_id_cur[%d] != wserv_id_pre[%d]\n",
                 "_wsta_roam_pkt_pmk_request",0x164,iVar2,local_428);
          local_3e3 = 1;
        }
      }
    }
    uac_wstation_free_sta_by_mac(__src,1);
  }
  else if (wsta_roam_warning_switch != '\0') {
    printf("[WSTA_ROAM_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n",
           "_wsta_roam_pkt_pmk_request",0x130);
  }
LAB_00486e28:
  FUN_0051ad88(&local_43c);
  local_444 = 0x12345678;
  local_440 = CONCAT22(0x49,local_440._2_2_);
  iVar2 = cw_service_msg_add(param_4,0x25,&local_444,1,0x49,&local_3e4);
  if ((iVar2 != 0) && (wsta_roam_err_switch != '\0')) {
    printf("[WSTA_ROAM_ERROR]%s()/%d set wsta assoc rslt vendor payload fail!\n",
           "_wsta_roam_pkt_pmk_request",0x18c);
  }
  return 0;
}

