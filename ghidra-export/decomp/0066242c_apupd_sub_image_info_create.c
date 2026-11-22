// func apupd_sub_image_info_create @ 0066242c size=484

int apupd_sub_image_info_create(undefined1 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[APUPD_ERROR]%32s() %05d: malloc pkt_buf fail\n\r\n","apupd_sub_image_info_create",0x2e1
          );
    return 0;
  }
  iVar2 = cw_parsed_pkt_create(0xf);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00662514;
    __format = "[APUPD_ERROR]%32s() %05d: malloc pkt fail\n\r\n";
    uVar4 = 0x2e7;
  }
  else {
    FUN_0051ad88(&local_40);
    local_34 = CONCAT13(1,CONCAT12(param_1,local_34._2_2_));
    local_30 = param_2;
    memcpy(&local_2c,param_3,0x10);
    cw_service_msg_add(iVar2,0x25,&local_48,1,0xb0,&local_34);
    iVar3 = capwap_packet_assemble(iVar1,iVar2);
    if (iVar3 != -1) {
      apupd_pkt_dump(iVar2);
      cw_parsed_pkt_destroy(iVar2);
      return iVar1;
    }
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_00662514;
    __format = "[APUPD_ERROR]%32s() %05d: assemble parsed packet failed. \r\n\r\n";
    uVar4 = 0x2f6;
  }
  printf(__format,"apupd_sub_image_info_create",uVar4);
LAB_00662514:
  cw_pkt_buf_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return 0;
}

