// func _uac_rdmngr_get_rd_entry @ 006249b8 size=5096

undefined4 _uac_rdmngr_get_rd_entry(int param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  byte bVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char local_360 [12];
  char acStack_354 [256];
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_240;
  undefined4 local_23c;
  short local_236;
  short local_234;
  short local_232;
  undefined1 auStack_21c [220];
  undefined1 auStack_140 [4];
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_12c;
  undefined4 local_128;
  short local_122;
  short local_120;
  short local_11e;
  
  local_360[0] = '\0';
  local_360[1] = '\0';
  local_360[2] = '\0';
  local_360[3] = '\0';
  local_360[4] = '\0';
  local_360[5] = '\0';
  local_360[6] = '\0';
  local_360[7] = '\0';
  local_360[8] = '\0';
  local_360[9] = '\0';
  memset(auStack_140,0,0x114);
  memset(&local_254,0,0x114);
  if (rdmngr_debug_switch == 0) {
    bVar7 = (byte)*param_2;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      bVar7 = (byte)*param_2;
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_get_rd_entry begins, radioId:%d\n",
             "_uac_rdmngr_get_rd_entry",299,*param_2);
      bVar7 = (byte)*param_2;
    }
  }
  iVar11 = param_1 + 0x218;
  iVar1 = apdb_get_radio_by_id
                    (*(undefined4 *)(param_1 + 0x40),iVar11,bVar7 & 0xf,auStack_140,
                     (int)*(char *)(param_2 + 2));
  if (iVar1 != 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[RDMNGR_ERROR]%s()/%d Get radio cfg from apdb failed of radio %d!\n",
           "_uac_rdmngr_get_rd_entry",0x12f,*param_2);
    return 0xffffffff;
  }
  iVar1 = json_object_new_object();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar6 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
    uVar5 = 0x136;
    goto LAB_00625b74;
  }
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",*param_2);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rf_id",uVar2);
  uVar2 = json_object_new_string(param_1 + 0x4e);
  json_object_object_add(iVar1,"ap_name",uVar2);
  if (*(int *)(param_1 + 0xc) == 0) {
    pcVar6 = "template";
  }
  else {
    pcVar6 = "ap";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"ap_type",uVar2);
  iVar10 = (int)*(char *)(param_2 + 2);
  if (iVar10 == -1) {
    strncpy(local_360,"UNKNOWN",9);
  }
  else {
    uVar9 = 1;
    uVar12 = 1;
    while (uVar9 < (*param_2 & 0xf)) {
      uVar2 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),uVar9);
      iVar3 = rdmngr_db_get_rd_freq_band(uVar2);
      if (iVar10 == iVar3) {
        uVar9 = uVar9 + 1;
        uVar12 = uVar12 + 1 & 0xff;
      }
      else {
        uVar9 = uVar9 + 1;
      }
    }
    if (iVar10 == 0) {
      puVar8 = &DAT_00693fd4;
    }
    else {
      puVar8 = &DAT_00693fd0;
    }
    snprintf(local_360,10,"%s%d",puVar8,uVar12);
  }
  uVar2 = json_object_new_string(local_360);
  json_object_object_add(iVar1,"rf_name",uVar2);
  pcVar6 = (char *)apdb_get_radio_freq_name_by_freq((int)*(char *)(param_2 + 2));
  if (pcVar6 == (char *)0x0) {
    pcVar6 = "---";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"freq_name",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(byte)*param_2 & 0xf);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"freq_unit",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 9));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"mode",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(short *)(param_2 + 3));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"channel",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)((int)param_2 + 10));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"bandwidth",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 0x19));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"power",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)((int)param_2 + 0x1a));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"max_usr",uVar2);
  if (*(char *)(param_2 + 0x12) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"rf_state",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)(param_2 + 7));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"antenna",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)((int)param_2 + 0x1e));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"frag_thr",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)(param_2 + 8));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"bcn_intvl",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 0x29));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"manage_frame_rate",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)(param_2 + 9));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rts_thr",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)((int)param_2 + 0x26));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"dtim_prd",uVar2);
  if (*(char *)((int)param_2 + 0x27) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,&DAT_006fe1c0,uVar2);
  if (*(char *)(param_2 + 10) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"brd_probe",uVar2);
  if (*(char *)((int)param_2 + 0x2a) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"short_gi",uVar2);
  if (*(char *)((int)param_2 + 0x2b) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"rssi_restrict",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)(param_2 + 0xb));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rssi_restrict_val",uVar2);
  iVar10 = rdmngr_profile_support_rssi_kick();
  if (iVar10 != 0) {
    if (*(char *)((int)param_2 + 0x2d) == '\0') {
      pcVar6 = "Led off";
    }
    else {
      pcVar6 = "Led on";
    }
    uVar2 = json_object_new_string(pcVar6 + 4);
    json_object_object_add(iVar1,"rssi_kick",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 0x2e));
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar1,"rssi_kick_val",uVar2);
  }
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)local_11e);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"min_tx_pwr",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)local_120);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"max_tx_pwr",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)local_122);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rf_max_usr",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",local_13c);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"supp_11ac",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",local_138);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"supp_11ax",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",local_12c);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"supp_11be",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",local_134);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"supp_160M",uVar2);
  memset(acStack_354,0,0x100);
  iVar10 = apdb_is_hdap_by_id(*(undefined4 *)(param_1 + 0x40),iVar11);
  snprintf(acStack_354,0x100,"%d",(uint)(iVar10 != 0));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"is_hdap",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",local_128);
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,&DAT_0070b7a4,uVar2);
  memset(acStack_354,0,0x100);
  iVar10 = apdb_is_hdap_by_id(*(undefined4 *)(param_1 + 0x40),iVar11);
  snprintf(acStack_354,0x100,"%d",(uint)(iVar10 != 0));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"is_hdap",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)((int)param_2 + 0xe));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,&DAT_00707dbc,uVar2);
  if (*(char *)(param_2 + 6) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"rf_online_switch",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)(param_2 + 4));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rf_check_circle",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)((int)param_2 + 0x12));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rf_chnl_occup_threshold",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(ushort *)((int)param_2 + 0x16));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"rf_chnl_tolerance",uVar2);
  if (*(short *)((int)param_2 + 0x22) == 0) {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"airtime",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 0x2f));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"reject_limit",uVar2);
  if (*(char *)(param_2 + 0xc) == '\0') {
    pcVar6 = "Led off";
  }
  else {
    pcVar6 = "Led on";
  }
  uVar2 = json_object_new_string(pcVar6 + 4);
  json_object_object_add(iVar1,"reject_enable",uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)((int)param_2 + 0x31));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"reject_diff",uVar2);
  if (*(char *)((int)param_2 + 0x32) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)((int)param_2 + 0x32) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"downlink_mumimo",uVar2);
  if (*(char *)((int)param_2 + 0x33) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)((int)param_2 + 0x33) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"uplink_mumimo",uVar2);
  if (*(char *)(param_2 + 0xd) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)(param_2 + 0xd) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"downlink_ofdma",uVar2);
  if (*(char *)((int)param_2 + 0x35) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)((int)param_2 + 0x35) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"uplink_ofdma",uVar2);
  if (*(char *)((int)param_2 + 0x36) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)((int)param_2 + 0x36) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,&DAT_00707e84,uVar2);
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(int)*(char *)((int)param_2 + 0x37));
  uVar2 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"gi_mode",uVar2);
  if (*(char *)(param_2 + 0xe) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)(param_2 + 0xe) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"enable_6g",uVar2);
  if (*(char *)((int)param_2 + 0x39) == -1) {
    pcVar6 = "null";
  }
  else if (*(char *)((int)param_2 + 0x39) == '\0') {
    pcVar6 = "off";
  }
  else {
    pcVar6 = "on";
  }
  uVar2 = json_object_new_string(pcVar6);
  json_object_object_add(iVar1,"enable_6g_psc",uVar2);
  puVar4 = (undefined1 *)
           apdb_get_radio_mutex_channel
                     (*(undefined4 *)(param_1 + 0x40),iVar11,(byte)*param_2 & 0xf,
                      *(undefined2 *)(param_1 + 0x10),(int)*(char *)(param_2 + 2));
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_00688af8;
  }
  uVar2 = json_object_new_string(puVar4);
  json_object_object_add(iVar1,"mutex_channel",uVar2);
  iVar10 = apdb_is_hdap_by_id(*(undefined4 *)(param_1 + 0x40),iVar11);
  if (iVar10 == 0) {
    iVar10 = apdb_get_dft_tx_pwr_by_id(*(undefined4 *)(param_1 + 0x40),iVar11,(byte)*param_2 & 0xf);
    if (iVar10 == -1) {
      iVar10 = (int)local_120;
    }
    else if (iVar10 == 0) {
      iVar10 = (int)local_120;
    }
    memset(acStack_354,0,0x100);
LAB_00625c88:
    snprintf(acStack_354,0x100,"%d",iVar10);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar1,"dft_tx_pwr",uVar2);
    bVar7 = (byte)*param_2;
  }
  else {
    if (*(char *)(param_2 + 2) == '\0') {
      memset(acStack_354,0,0x100);
      iVar10 = rdmngr_db_get_hdap_1800_dft_tx_pwr_2_4G();
      goto LAB_00625c88;
    }
    if (*(char *)(param_2 + 2) == '\x01') {
      memset(acStack_354,0,0x100);
      iVar10 = rdmngr_db_get_hdap_1800_dft_tx_pwr_5G();
      goto LAB_00625c88;
    }
    bVar7 = (byte)*param_2;
  }
  iVar10 = apdb_get_multi_radio_by_id
                     (*(undefined4 *)(param_1 + 0x40),iVar11,bVar7 & 0xf,&local_254,
                      (int)*(char *)(param_2 + 2));
  if (iVar10 == 0) {
    iVar10 = json_object_new_object();
    if (iVar10 == 0) {
      json_object_put(iVar1);
      uVar2 = 0xffffffff;
      if (rdmngr_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar6 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
      uVar5 = 0x1a0;
      goto LAB_00625b74;
    }
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",(int)local_232);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"min_tx_pwr",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",(int)local_234);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"max_tx_pwr",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",(int)local_236);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"rf_max_usr",uVar2);
    iVar11 = apdb_get_dft_tx_pwr_by_id
                       (*(undefined4 *)(param_1 + 0x40),iVar11,(byte)*param_2 & 0xf,local_254);
    if (iVar11 == -1) {
      iVar11 = (int)local_234;
    }
    else if (iVar11 == 0) {
      iVar11 = (int)local_234;
    }
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",iVar11);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"dft_tx_pwr",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",local_250);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"supp_11ac",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",local_24c);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"supp_11ax",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",local_240);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"supp_11be",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",local_248);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,"supp_160M",uVar2);
    memset(acStack_354,0,0x100);
    snprintf(acStack_354,0x100,"%d",local_23c);
    uVar2 = json_object_new_string(acStack_354);
    json_object_object_add(iVar10,&DAT_0070b7a4,uVar2);
    uVar2 = json_object_new_string(auStack_21c);
    json_object_object_add(iVar10,"mutex_channel",uVar2);
    json_object_object_add(iVar1,"multi_radio",iVar10);
  }
  uVar2 = 0;
  memset(acStack_354,0,0x100);
  snprintf(acStack_354,0x100,"%d",(uint)*(byte *)(param_1 + 0x2d1));
  uVar5 = json_object_new_string(acStack_354);
  json_object_object_add(iVar1,"region_code",uVar5);
  json_object_array_add(param_3,iVar1);
  if (rdmngr_debug_switch == 0) {
    return 0;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return 0;
  }
  pcVar6 = "[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_get_rd_entry finishes\n";
  uVar5 = 0x1b5;
LAB_00625b74:
  printf(pcVar6,"_uac_rdmngr_get_rd_entry",uVar5);
  return uVar2;
}

