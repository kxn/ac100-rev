// func apupd_large_image_info_create @ 00661fc8 size=480

int apupd_large_image_info_create(undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [28];
  
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  memset(local_44,0,0x20);
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    if (g_apupd_error == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("[APUPD_ERROR]%32s() %05d: malloc pkt_buf fail\n\r\n","apupd_large_image_info_create",
           0x267);
    return 0;
  }
  iVar2 = cw_parsed_pkt_create(7);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_006620a8;
    __format = "[APUPD_ERROR]%32s() %05d: malloc pkt fail\n\r\n";
    uVar4 = 0x26d;
  }
  else {
    FUN_0051ad88(&local_50);
    local_44[0] = 1;
    local_40 = param_1;
    local_3c = param_2;
    memcpy(auStack_38,param_3,0x10);
    cw_service_msg_add(iVar2,0x25,&local_58,1,0xaf,local_44);
    iVar3 = capwap_packet_assemble(iVar1,iVar2);
    if (iVar3 != -1) {
      apupd_pkt_dump(iVar2);
      cw_parsed_pkt_destroy(iVar2);
      return iVar1;
    }
    if ((g_apupd_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_006620a8;
    __format = "[APUPD_ERROR]%32s() %05d: assemble parsed packet failed. \r\n\r\n";
    uVar4 = 0x27c;
  }
  printf(__format,"apupd_large_image_info_create",uVar4);
LAB_006620a8:
  cw_pkt_buf_destroy(iVar1);
  if (iVar2 != 0) {
    cw_parsed_pkt_destroy(iVar2);
  }
  return 0;
}

