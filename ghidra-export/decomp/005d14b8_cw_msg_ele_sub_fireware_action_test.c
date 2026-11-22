// func cw_msg_ele_sub_fireware_action_test @ 005d14b8 size=1

void cw_msg_ele_sub_fireware_action_test(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  puts("cw_msg_ele_sub_fireware_action_test start()");
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_38 = 0;
  uStack_34 = 0;
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
      FUN_0051ad88(&uStack_28);
      uStack_38 = CONCAT13(param_1,CONCAT12(param_2,uStack_38._2_2_));
      uStack_34 = param_3;
      puts("cw_msg_ele_sub_fireware_action_test add msg");
      cw_service_msg_add(iVar2,0x25,&uStack_30,1,0xb1,&uStack_38);
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
      __s = "cw_msg_ele_sub_fireware_action_test end()";
    }
  }
  puts(__s);
  return;
}

