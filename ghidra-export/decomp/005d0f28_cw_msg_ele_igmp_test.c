// func cw_msg_ele_igmp_test @ 005d0f28 size=1

void cw_msg_ele_igmp_test(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__s;
  int iVar5;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined2 uStack_e8;
  undefined4 uStack_e4;
  undefined2 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined1 *puStack_d0;
  undefined4 uStack_cc;
  undefined4 *puStack_c8;
  undefined4 uStack_c4;
  undefined4 *puStack_c0;
  undefined4 uStack_bc;
  undefined4 *puStack_b8;
  undefined1 auStack_b4 [4];
  undefined1 uStack_b0;
  undefined4 uStack_ac;
  undefined1 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_84 [8];
  undefined1 auStack_7c [12];
  undefined1 auStack_70 [20];
  undefined1 auStack_5c [20];
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [24];
  
  puts("cw_msg_ele_igmp_test start()");
  memset(auStack_84,0,100);
  uStack_bc = 0;
  puStack_b8 = (undefined4 *)0x0;
  uStack_c4 = 0;
  puStack_c0 = (undefined4 *)0x0;
  uStack_f0 = 0;
  uStack_cc = 0;
  puStack_c8 = (undefined4 *)0x0;
  uStack_d4 = 0;
  puStack_d0 = (undefined1 *)0x0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_ec = 0;
  uStack_e8 = 0;
  memset(auStack_b4,0,0x30);
  iVar2 = cw_pkt_buf_create(0xfa);
  if (iVar2 == 0) {
    __s = "malloc pkt_buf fail";
  }
  else {
    iVar5 = 0;
    iVar3 = cw_parsed_pkt_create(7);
    if (iVar3 == 0) {
      __s = "malloc pkt fail";
    }
    else {
      iVar4 = 0;
      do {
        iVar5 = iVar5 + 1;
        FUN_0051ad88(auStack_84 + iVar4 + 8);
        iVar4 = iVar5 * 0x14;
      } while (iVar5 != 5);
      puStack_c0 = &uStack_e4;
      uVar1 = (undefined1)uStack_bc;
      puStack_b8 = &uStack_dc;
      uStack_bc._1_3_ = (uint3)CONCAT11(2,uVar1);
      uStack_bc = CONCAT13(1,uStack_bc._1_3_);
      uStack_f0 = CONCAT22(0x14,CONCAT11(200,(undefined1)uStack_f0));
      puStack_c8 = &uStack_ec;
      uStack_b0 = 1;
      uStack_98 = 1;
      uStack_ac = 0x1e240;
      uStack_c4 = 2;
      uStack_cc = 2;
      uStack_d4 = 2;
      puStack_d0 = auStack_b4;
      uStack_94 = 0xf1206;
      puts("cw_msg_ele_igmp_test add msg");
      cw_service_msg_add(iVar3,0x25,auStack_84,1,0x70,&uStack_bc);
      cw_service_msg_add(iVar3,0x25,auStack_70,1,0x71,&uStack_c4);
      cw_service_msg_add(iVar3,0x25,auStack_5c,1,0x72,&uStack_f0);
      cw_service_msg_add(iVar3,0x25,auStack_48,1,0x73,&uStack_cc);
      cw_service_msg_add(iVar3,0x25,auStack_34,1,0x74,&uStack_d4);
      iVar5 = capwap_packet_assemble(iVar2,iVar3);
      if (iVar5 == -1) {
        puts("assemble parsed packet failed. \r");
      }
      else {
        capwap_parsed_packet_dump(iVar3);
        cw_pkt_buf_dump(iVar2);
      }
      cw_parsed_pkt_destroy(iVar3);
      cw_pkt_buf_destroy(iVar2);
      __s = "cw_msg_ele_igmp_test end()";
    }
  }
  puts(__s);
  return;
}

