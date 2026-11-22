// func cw_fsm_ac_enter_reset @ 0059ced8 size=272

undefined4 cw_fsm_ac_enter_reset(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [20];
  undefined2 local_2c;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_enter_reset",0x125,"session");
  }
  else {
    memset(auStack_50,0,0x34);
    memcpy(auStack_40,(void *)(param_1 + 0x2c),0x14);
    local_2c = *(undefined2 *)(param_1 + 0x40);
    cw_fsm_ac_change_state(param_1,10);
    if (*(int *)(param_1 + 0x10) != 0) {
      memcpy(auStack_50,(void *)(param_1 + 0x14),6);
    }
    iVar1 = 0;
    if ((param_2 != 0) && (iVar1 = cw_parsed_pkt_create(0x11), iVar1 == 0)) {
      return 0xffffffff;
    }
    serv_ent_handle(2,auStack_50,iVar1,0);
    uVar2 = 0;
    if (param_2 != 0) {
      ac_packet_send(param_1,iVar1);
      cw_parsed_pkt_destroy(iVar1);
    }
  }
  return uVar2;
}

