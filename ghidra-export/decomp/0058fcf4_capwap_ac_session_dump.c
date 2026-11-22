// func capwap_ac_session_dump @ 0058fcf4 size=316

void capwap_ac_session_dump(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_70 [64];
  uint local_30;
  
  if (param_1 != 0) {
    memset(auStack_70,0,0x40);
    FUN_00408190(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                 *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c),auStack_70,0x40,"---");
    local_30 = (uint)*(byte *)(param_1 + 0x14);
    uVar6 = *(ushort *)(param_1 + 0x40);
    bVar1 = *(byte *)(param_1 + 0x15);
    bVar2 = *(byte *)(param_1 + 0x16);
    bVar3 = *(byte *)(param_1 + 0x17);
    bVar4 = *(byte *)(param_1 + 0x18);
    bVar5 = *(byte *)(param_1 + 0x19);
    uVar7 = cw_fsm_get_state_name(*(undefined4 *)(param_1 + 0xb4));
    uVar8 = FUN_00407fe0(param_1 + 0xf8);
    printf("ip/port:%s/%d\tmac:%02x-%02x-%02x-%02x-%02x-%02x\tstate:%s\trtx_size:%d rtx_para:%d/%d(%d/%d/%d):\r\n"
           ,auStack_70,(uint)uVar6,local_30,(uint)bVar1,(uint)bVar2,(uint)bVar3,(uint)bVar4,
           (uint)bVar5,uVar7,uVar8,(int)*(short *)(param_1 + 0xf4),(int)*(char *)(param_1 + 0xf6),
           (int)*(short *)(param_1 + 0xf0),(int)*(char *)(param_1 + 0xf7),
           (int)*(char *)(param_1 + 0xf2));
  }
  return;
}

