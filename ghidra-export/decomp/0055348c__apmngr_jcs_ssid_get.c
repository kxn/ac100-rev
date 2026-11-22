// func _apmngr_jcs_ssid_get @ 0055348c size=872

undefined4 _apmngr_jcs_ssid_get(uint *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  ushort local_138 [2];
  char local_134 [280];
  
  local_134[0] = '\0';
  local_134[1] = '\0';
  local_134[2] = '\0';
  local_134[3] = '\0';
  local_134[4] = '\0';
  local_134[5] = '\0';
  local_134[6] = '\0';
  local_134[7] = '\0';
  local_134[8] = '\0';
  local_134[9] = '\0';
  local_134[10] = '\0';
  local_134[0xb] = '\0';
  local_134[0xc] = '\0';
  local_134[0xd] = '\0';
  local_134[0xe] = '\0';
  local_134[0xf] = '\0';
  local_134[0x10] = '\0';
  local_134[0x11] = '\0';
  local_134[0x12] = '\0';
  local_134[0x13] = '\0';
  local_138[0] = 0;
  if (param_3 == (int *)0x0) {
    return 0xffffffff;
  }
  if (param_3[9] == 0) {
    return 0xffffffff;
  }
  param_3[2] = param_3[2] + 1;
  if (param_3[1] < 1) {
    return 0;
  }
  if (0 < *param_3) {
    *param_3 = *param_3 + -1;
    return 0;
  }
  param_3[1] = param_3[1] + -1;
  iVar1 = rdmngr_db_get_rd_freq_band(*param_1);
  iVar2 = *(int *)(param_2 + 0x16a);
  if (iVar2 == 2) {
    pcVar4 = "WPA/WPA2";
  }
  else {
    if (iVar2 == 4) {
      if ((iVar1 != -1) &&
         (iVar2 = apdb_support_wpa3_by_id(param_3[4],param_3 + 5,*param_1 & 0xf,iVar1), iVar2 != 0))
      {
        pcVar4 = "WPA2-PSK/WPA3-SAE";
        goto LAB_00553574;
      }
    }
    else if (iVar2 != 1) {
      pcVar4 = "---";
      goto LAB_00553574;
    }
    pcVar4 = "WPA-PSK/WPA2-PSK";
  }
LAB_00553574:
  strncpy(local_134,pcVar4,0x13);
  iVar2 = json_object_new_object();
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
             "_apmngr_jcs_ssid_get",0xb89);
    }
  }
  else {
    memset(local_134 + 0x14,0,0x100);
    snprintf(local_134 + 0x14,0x100,"%d",*param_1 & 0xf);
    uVar3 = json_object_new_string(local_134 + 0x14);
    json_object_object_add(iVar2,"freq_unit",uVar3);
    pcVar4 = (char *)apdb_get_radio_freq_name_by_freq(iVar1);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = "---";
    }
    uVar3 = json_object_new_string(pcVar4);
    json_object_object_add(iVar2,"freq_name",uVar3);
    uVar3 = json_object_new_string(param_2 + 0x130);
    json_object_object_add(iVar2,"ssid",uVar3);
    memset(local_134 + 0x14,0,0x100);
    snprintf(local_134 + 0x14,0x100,"%d",*(undefined4 *)(param_2 + 300));
    uVar3 = json_object_new_string(local_134 + 0x14);
    json_object_object_add(iVar2,"encode",uVar3);
    uVar3 = json_object_new_string(param_2 + 0x84);
    json_object_object_add(iVar2,&DAT_006ce874,uVar3);
    wserv_db_rd_get_bind_vlan_by_wlan_id(*param_1,*(undefined1 *)(param_1 + 1),local_138);
    memset(local_134 + 0x14,0,0x100);
    snprintf(local_134 + 0x14,0x100,"%d",(uint)local_138[0]);
    uVar3 = json_object_new_string(local_134 + 0x14);
    json_object_object_add(iVar2,"vlan_id",uVar3);
    uVar3 = json_object_new_string(local_134);
    json_object_object_add(iVar2,"encryption",uVar3);
    memset(local_134 + 0x14,0,0x100);
    uVar5 = 0;
    if (param_3[3] != 0) {
      uVar5 = (uint)(*(int *)(param_2 + 0x11b) != 0);
    }
    snprintf(local_134 + 0x14,0x100,"%d",uVar5);
    uVar3 = json_object_new_string(local_134 + 0x14);
    json_object_object_add(iVar2,"status",uVar3);
    uVar3 = 0;
    json_object_array_add(param_3[9],iVar2);
  }
  return uVar3;
}

