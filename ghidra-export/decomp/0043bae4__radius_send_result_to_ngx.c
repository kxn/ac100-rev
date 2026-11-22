// func _radius_send_result_to_ngx @ 0043bae4 size=1604

undefined4 _radius_send_result_to_ngx(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char local_98 [64];
  undefined1 auStack_58 [72];
  
  memset(auStack_58,0,0x41);
  local_98[0] = '\0';
  local_98[1] = '\0';
  local_98[2] = '\0';
  local_98[3] = '\0';
  local_98[4] = '\0';
  local_98[5] = '\0';
  local_98[6] = '\0';
  local_98[7] = '\0';
  local_98[8] = '\0';
  local_98[9] = '\0';
  local_98[10] = '\0';
  local_98[0xb] = '\0';
  local_98[0xc] = '\0';
  local_98[0xd] = '\0';
  local_98[0xe] = '\0';
  local_98[0xf] = '\0';
  local_98[0x10] = '\0';
  local_98[0x11] = '\0';
  local_98[0x12] = '\0';
  local_98[0x13] = '\0';
  memset(local_98 + 0x14,0,0x29);
  memcpy(auStack_58,(void *)(param_1 + 0x506),0x40);
  sprintf(local_98,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x547),
          (uint)*(byte *)(param_1 + 0x548),(uint)*(byte *)(param_1 + 0x549),
          (uint)*(byte *)(param_1 + 0x54a),(uint)*(byte *)(param_1 + 0x54b),
          (uint)*(byte *)(param_1 + 0x54c));
  if ((*(char *)(param_1 + 0x629) == ' ') && ((*(byte *)(param_1 + 0x62c) & 2) == 0)) {
    if (radius_debug_switch != 0) {
      printf("[RADIUS_DEBUG]%s()/%d Radius cmcc result\n","_radius_send_result_to_ngx",0x2ed);
    }
    iVar1 = 4;
    if ((uint)param_2[2] < 4) {
      iVar1 = (int)(char)(&DAT_00682f28)[param_2[2]];
    }
    uVar2 = 0;
    if (*(char *)(param_1 + 0x57c) == '\x01') {
      uVar2 = *(undefined4 *)(param_1 + 0x580);
    }
    iVar1 = wportal_cmcc_radius_result(param_1 + 0x547,uVar2,iVar1);
    if (iVar1 != 0) {
      if (radius_debug_switch == 0) {
        return 0xffffffff;
      }
      printf("[RADIUS_DEBUG]%s()/%d Cmcc portal radius result error\n","_radius_send_result_to_ngx",
             0x30c);
      return 0xffffffff;
    }
  }
  iVar1 = json_object_new_object();
  uVar2 = json_object_new_string(local_98);
  json_object_object_add(iVar1,"mac",uVar2);
  uVar2 = json_object_new_int((int)*(char *)(param_1 + 0x629));
  json_object_object_add(iVar1,"auth_type",uVar2);
  uVar2 = json_object_new_int(param_2[2]);
  json_object_object_add(iVar1,"result",uVar2);
  uVar2 = json_object_new_int64(0,param_2[3]);
  json_object_object_add(iVar1,"expire_time",uVar2);
  uVar2 = json_object_new_string(auStack_58);
  json_object_object_add(iVar1,"token",uVar2);
  uVar2 = json_object_new_int(param_2[1]);
  json_object_object_add(iVar1,"account_port",uVar2);
  uVar2 = json_object_new_int(*(undefined4 *)(param_1 + 0x604));
  json_object_object_add(iVar1,"useBackup",uVar2);
  uVar2 = json_object_new_int64(*(undefined4 *)(param_1 + 0x568),*(undefined4 *)(param_1 + 0x56c));
  json_object_object_add(iVar1,"acctSessid",uVar2);
  uVar2 = json_object_new_int(param_2[4]);
  json_object_object_add(iVar1,"update_intvl",uVar2);
  uVar2 = json_object_new_int(*param_2);
  json_object_object_add(iVar1,"radius_index",uVar2);
  uVar2 = json_object_new_int64(0,*(undefined4 *)(param_1 + 0x5e0));
  json_object_object_add(iVar1,"up_limit",uVar2);
  uVar2 = json_object_new_int64(0,*(undefined4 *)(param_1 + 0x5e4));
  json_object_object_add(iVar1,"down_limit",uVar2);
  uVar2 = json_object_new_int64(*(undefined4 *)(param_1 + 0x630),*(undefined4 *)(param_1 + 0x634));
  json_object_object_add(iVar1,"upstream_load",uVar2);
  uVar2 = json_object_new_int64(*(undefined4 *)(param_1 + 0x638),*(undefined4 *)(param_1 + 0x63c));
  json_object_object_add(iVar1,"downstream_load",uVar2);
  uVar2 = json_object_new_int64((int)param_2[8] >> 0x1f);
  json_object_object_add(iVar1,"error_cause",uVar2);
  uac_ipaddr_convert_binary2str
            (*(undefined4 *)(param_1 + 0x57c),*(undefined4 *)(param_1 + 0x580),
             *(undefined4 *)(param_1 + 0x584),*(undefined4 *)(param_1 + 0x588),
             *(undefined4 *)(param_1 + 0x58c),local_98 + 0x14,0x28,"---");
  uVar2 = json_object_new_string(local_98 + 0x14);
  json_object_object_add(iVar1,&DAT_00677c24,uVar2);
  if ((*(byte *)(param_1 + 0x62c) & 4) == 0) {
    iVar3 = wportal_get_mode();
    if (iVar3 == 1) {
      uVar2 = json_object_new_int(*(undefined4 *)(param_1 + 0x608));
      pcVar4 = "vlan_id";
    }
    else {
      iVar3 = wportal_get_mode();
      if (iVar3 == 0) {
        uVar2 = json_object_new_int(*(undefined4 *)(param_1 + 0x608));
        pcVar4 = "serv_id";
      }
      else {
        iVar3 = wportal_get_mode();
        if (iVar3 != 2) goto LAB_0043bf50;
        uVar2 = json_object_new_string(param_1 + 0x553);
        pcVar4 = "interface";
      }
    }
  }
  else {
    uVar2 = json_object_new_string("1");
    json_object_object_add(iVar1,"is_common",uVar2);
    uVar2 = json_object_new_string(param_1 + 0x41c);
    pcVar4 = "username";
  }
  json_object_object_add(iVar1,pcVar4,uVar2);
LAB_0043bf50:
  uVar2 = json_object_new_int(3);
  json_object_object_add(iVar1,"type",uVar2);
  wportal_send_to_nginx(iVar1);
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  return 0;
}

