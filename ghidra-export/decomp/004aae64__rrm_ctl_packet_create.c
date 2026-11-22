// func _rrm_ctl_packet_create @ 004aae64 size=520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_rrm_ctl_packet_create
          (undefined4 param_1,undefined1 param_2,uint param_3,undefined1 param_4,undefined1 param_5,
          undefined1 param_6)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_55;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  memset(&local_5c,0,0x34);
  iVar1 = cw_parsed_pkt_create(7);
  if (iVar1 == 0) {
    if (rrm_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[RRM_ERROR]%s()/%d cw_parsed_pkt_create failed\n","_rrm_ctl_packet_create",0x1bd);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_68);
  local_4b = param_5;
  local_4a = param_6;
  local_5c = _ctl;
  local_58 = _DAT_00731908;
  local_55 = DAT_0073190a;
  local_54 = DAT_0073190c;
  local_52 = DAT_0073190e;
  local_50 = DAT_00731910;
  local_4e = DAT_00731912;
  local_49 = 1;
  local_48 = (&DAT_00767bd1)[(param_3 & 0xff) * 5];
  local_56 = param_2;
  local_4c = param_4;
  iVar2 = cw_service_msg_add(iVar1,0x25,&local_70,1,0x5c,&local_5c);
  if (iVar2 == 0) {
    rrm_pkt_dump(iVar1);
    iVar2 = capwap_packet_assemble(param_1,iVar1);
    if (iVar2 != -1) {
      cw_parsed_pkt_destroy(iVar1);
      return 0;
    }
    if (rrm_err_switch == '\0') goto LAB_004aaf90;
    __format = "[RRM_ERROR]%s()/%d capwap_packet_assemble failed\n";
    uVar3 = 0x1dd;
  }
  else {
    if (rrm_err_switch == '\0') goto LAB_004aaf90;
    __format = "[RRM_ERROR]%s()/%d cw_service_msg_add failed\n";
    uVar3 = 0x1d6;
  }
  printf(__format,"_rrm_ctl_packet_create",uVar3);
LAB_004aaf90:
  cw_parsed_pkt_destroy(iVar1);
  return 0xffffffff;
}

