// func packet_public_mesh_assemble_test @ 005d1a04 size=1

undefined4 packet_public_mesh_assemble_test(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 *puStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  puStack_24 = (undefined4 *)0x0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_4c = 0;
  uStack_50 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uVar1 = cw_pkt_buf_create(0xfa);
  uVar2 = cw_parsed_pkt_create(7);
  uStack_50 = 1;
  FUN_0051ad88(&uStack_1c);
  FUN_0051ad88(&uStack_34);
  uStack_28 = CONCAT22(2,uStack_28._2_2_);
  puStack_24 = &uStack_48;
  uStack_4c = 0xc0a80101;
  cw_priv_mesh_public_control_add(&uStack_28,0x1e,&uStack_4c,0);
  cw_priv_mesh_public_control_add(&uStack_28,0x25,&uStack_3c,1,0x6f,&uStack_50);
  cw_service_msg_add(uVar2,0x25,&uStack_3c,1,0x75,&uStack_28);
  iVar3 = capwap_packet_assemble(uVar1,uVar2);
  if (iVar3 == -1) {
    puts("assemble parsed packet failed. \r");
  }
  else {
    capwap_parsed_packet_dump(uVar2);
    cw_pkt_buf_dump(uVar1);
  }
  cw_priv_mesh_public_control_sub_ele_free(&uStack_28);
  cw_parsed_pkt_destroy(uVar2);
  cw_pkt_buf_destroy(uVar1);
  return 0;
}

