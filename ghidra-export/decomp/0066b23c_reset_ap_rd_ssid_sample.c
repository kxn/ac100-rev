// func reset_ap_rd_ssid_sample @ 0066b23c size=252

void reset_ap_rd_ssid_sample(int param_1,void *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (param_1 == 0) {
    uVar2 = *(undefined4 *)((int)param_2 + 0x3c);
    uVar1 = *(undefined4 *)((int)param_2 + 0x38);
    uVar4 = *(undefined4 *)((int)param_2 + 0x24);
    uVar3 = *(undefined4 *)((int)param_2 + 0x20);
    uVar6 = *(undefined4 *)((int)param_2 + 0x2c);
    uVar5 = *(undefined4 *)((int)param_2 + 0x28);
    uVar8 = *(undefined4 *)((int)param_2 + 0x34);
    uVar7 = *(undefined4 *)((int)param_2 + 0x30);
    memset(param_2,0,0x100);
    *(undefined4 *)((int)param_2 + 0x14) = 0xffffffff;
    *(undefined4 *)((int)param_2 + 0x18) = 0xffffffff;
    *(undefined4 *)((int)param_2 + 0x58) = 0xffffffff;
    *(undefined4 *)((int)param_2 + 0x5c) = 0xffffffff;
    *(undefined4 *)((int)param_2 + 0x24) = uVar4;
    *(undefined4 *)((int)param_2 + 0x20) = uVar3;
    *(undefined4 *)((int)param_2 + 0x2c) = uVar6;
    *(undefined4 *)((int)param_2 + 0x28) = uVar5;
    *(undefined4 *)((int)param_2 + 0x34) = uVar8;
    *(undefined4 *)((int)param_2 + 0x30) = uVar7;
    *(undefined4 *)((int)param_2 + 0x3c) = uVar2;
    *(undefined4 *)((int)param_2 + 0x38) = uVar1;
    return;
  }
  memset(param_2,0,0x100);
  return;
}

