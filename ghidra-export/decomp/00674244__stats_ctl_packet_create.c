// func _stats_ctl_packet_create @ 00674244 size=444

undefined4 _stats_ctl_packet_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  iVar1 = cw_parsed_pkt_create(7);
  if (iVar1 == 0) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d cw_parsed_pkt_create failed\n","_stats_ctl_packet_create",
           0x19b);
    return 0xffffffff;
  }
  FUN_0051ad88(&local_20);
  iVar2 = stats_db_ctl_get(&local_40);
  if (iVar2 == -1) {
    if (stats_err_switch == '\0') goto LAB_00674350;
    __format = "[STATISTICS_ERROR]%s()/%d stats_db_ctl_get failed\n";
    uVar3 = 0x1a5;
  }
  else {
    local_34 = CONCAT22((short)((uint)local_40 >> 0x10),
                        CONCAT11(local_40._2_1_,(undefined1)local_34));
    local_30 = local_3c;
    local_2c = local_38;
    iVar2 = cw_service_msg_add(iVar1,0x25,&local_28,1,0x55,&local_34);
    if (iVar2 == 0) {
      iVar2 = capwap_packet_assemble(param_1,iVar1);
      if (iVar2 != -1) {
        cw_parsed_pkt_destroy(iVar1);
        return 0;
      }
      if (stats_err_switch == '\0') goto LAB_00674350;
      __format = "[STATISTICS_ERROR]%s()/%d capwap_packet_assemble failed\n";
      uVar3 = 0x1ba;
    }
    else {
      if (stats_err_switch == '\0') goto LAB_00674350;
      __format = "[STATISTICS_ERROR]%s()/%d cw_service_msg_add failed\n";
      uVar3 = 0x1b2;
    }
  }
  printf(__format,"_stats_ctl_packet_create",uVar3);
LAB_00674350:
  cw_parsed_pkt_destroy(iVar1);
  return 0xffffffff;
}

