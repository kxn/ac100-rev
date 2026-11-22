// func _sensor_di_collect_pkt_stat_data_parse_subpktdata @ 004d4b4c size=500

undefined4 _sensor_di_collect_pkt_stat_data_parse_subpktdata(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = json_object_get_type();
  if (iVar1 != 5) {
    return 0xffffffff;
  }
  iVar1 = json_object_array_length(param_1);
  if (iVar1 < 1) {
    return 0xffffffff;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  iVar1 = json_object_array_length(param_1);
  if (iVar1 < 3) {
    if (sensor_di_debug_switch == 0) {
      return 0xffffffff;
    }
    printf("[SENSOR_DI_DEBUG]%s()/line %d : invalid subpktdata length\n",
           "_sensor_di_collect_pkt_stat_data_parse_subpktdata",0x266);
    return 0xffffffff;
  }
  iVar1 = json_object_array_get_idx(param_1,0);
  if (iVar1 == 0) {
LAB_004d4c14:
    uVar3 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_sensor_di_collect_pkt_stat_data_parse_subpktdata",0x26c);
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d4c14;
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
  }
  param_2[1] = uVar3;
  iVar1 = json_object_array_get_idx(param_1,2);
  if (iVar1 == 0) {
LAB_004d4c64:
    if (jcs_err_switch == 0) {
      *param_2 = 0xffffffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_sensor_di_collect_pkt_stat_data_parse_subpktdata",0x270);
      *param_2 = 0xffffffff;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_004d4c64;
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    }
    *param_2 = uVar3;
  }
  return 0;
}

