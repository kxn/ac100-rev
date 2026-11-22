// func _radius_send_dm_response @ 00408b5c size=1

undefined4
_radius_send_dm_response
          (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,int param_5,
          undefined4 param_6,char *param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  code *pcVar4;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  pcVar4 = *(code **)(in_t9 + 0x350c94);
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  *param_2 = *param_7;
  param_2[1] = param_7[0x18];
  (*pcVar4)(param_2 + 4,param_7 + 8,0x10);
  if ((*param_7 == '*') || (iVar3 = 0x14, *param_7 == '-')) {
    (**(code **)(in_t9 + 0x350640))(param_1,param_7 + 0x1c,0x65,param_7 + 4,0xffffffff,0);
    iVar3 = (*(code *)(*(int *)(in_t9 + 0x3505ec) + -0x3dd0))
                      (*(undefined4 *)(param_7 + 0x1c),0,param_2);
    iVar3 = iVar3 + 0x14;
  }
  pcVar4 = *(code **)(in_t9 + 0x350c94);
  *(short *)(param_2 + 2) = (short)iVar3;
  (*pcVar4)(param_2 + iVar3,param_6,0x78);
  iVar1 = (**(code **)(in_t9 + 0x350ac0))(param_6);
  (*(code *)(*(int *)(in_t9 + 0x3505ec) + -0x3e50))(&uStack_30,param_2,iVar3 + iVar1);
  (**(code **)(in_t9 + 0x350c94))(param_2 + 4,&uStack_30,0x10);
  if (param_5 == 1) {
    iVar3 = (**(code **)(in_t9 + 0x350bd0))(param_3,param_2,iVar3,0,param_4,0x10);
    if (-1 < iVar3) {
      return 0;
    }
    if (**(int **)(in_t9 + 0x3505d8) == 0) {
      return 0xffffffff;
    }
    iVar3 = *(int *)(in_t9 + 0x3505c4);
    uVar2 = 0xe6e;
    iVar1 = *(int *)(in_t9 + 0x3505c4);
  }
  else {
    iVar3 = (**(code **)(in_t9 + 0x350bd0))(param_3,param_2,iVar3,0,param_4,0x1c);
    if (-1 < iVar3) {
      return 0;
    }
    if (**(int **)(in_t9 + 0x3505d8) == 0) {
      return 0xffffffff;
    }
    iVar3 = *(int *)(in_t9 + 0x3505c4);
    uVar2 = 0xe77;
    iVar1 = *(int *)(in_t9 + 0x3505c4);
  }
  (**(code **)(in_t9 + 0x350d74))(iVar3 + 0x1734,iVar1 + 0x2de4,uVar2);
  return 0xffffffff;
}

