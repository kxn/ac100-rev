// func cw_msg_ele_sub_fireware_info_test @ 005d133c size=1

void cw_msg_ele_sub_fireware_info_test(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [32];
  
  puts("cw_msg_ele_sub_fireware_info_test start()");
  uStack_68 = 0;
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  memcpy(auStack_38,&UNK_006f25c0,0x20);
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 == 0) {
    __s = "malloc pkt_buf fail";
  }
  else {
    iVar2 = cw_parsed_pkt_create(7);
    if (iVar2 == 0) {
      __s = "malloc pkt fail";
    }
    else {
      FUN_0051ad88(&uStack_60);
      uStack_54 = CONCAT13(param_1,CONCAT12(param_2,uStack_54._2_2_));
      uStack_50 = param_3;
      memcpy(&uStack_4c,auStack_38,0x10);
      puts("cw_msg_ele_sub_fireware_info_test add msg");
      cw_service_msg_add(iVar2,0x25,&uStack_68,1,0xb0,&uStack_54);
      iVar3 = capwap_packet_assemble(iVar1,iVar2);
      if (iVar3 == -1) {
        puts("assemble parsed packet failed. \r");
      }
      else {
        capwap_parsed_packet_dump(iVar2);
        cw_pkt_buf_dump(iVar1);
      }
      cw_parsed_pkt_destroy(iVar2);
      cw_pkt_buf_destroy(iVar1);
      __s = "cw_msg_ele_sub_fireware_info_test end()";
    }
  }
  puts(__s);
  return;
}

