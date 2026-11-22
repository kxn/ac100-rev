// func cw_msg_ele_large_fireware_info_test @ 005d11c4 size=1

void cw_msg_ele_large_fireware_info_test(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [32];
  undefined1 auStack_44 [4];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [28];
  
  puts("cw_msg_ele_large_fireware_info_test start()");
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  memset(auStack_44,0,0x20);
  memcpy(auStack_64,&UNK_006f25c0,0x20);
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
      FUN_0051ad88(&uStack_70);
      auStack_44[0] = param_1;
      uStack_40 = param_2;
      uStack_3c = param_3;
      memcpy(auStack_38,auStack_64,0x10);
      puts("cw_msg_ele_large_fireware_info_test add msg");
      cw_service_msg_add(iVar2,0x25,&uStack_78,1,0xaf,auStack_44);
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
      __s = "cw_msg_ele_large_fireware_info_test end()";
    }
  }
  puts(__s);
  return;
}

