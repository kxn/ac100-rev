// func uac_compute_timeout @ 0052437c size=1

undefined4 uac_compute_timeout(int *param_1,int param_2)

{
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  int extraout_v1_02;
  uint uVar1;
  uint uVar2;
  int in_t9;
  code *pcVar3;
  int iStack_28;
  int iStack_24;
  
  (**(code **)(in_t9 + 0x235320))(&iStack_28,0);
  uVar2 = iStack_24 * 1000;
  pcVar3 = *(code **)(in_t9 + 0x235534);
  param_1[1] = uVar2;
  (*pcVar3)(param_2 >> 0x1f,param_2,0,1000000);
  *param_1 = iStack_28 + extraout_v1;
  (**(code **)(in_t9 + 0x235368))(param_2 >> 0x1f,param_2,0,1000000);
  uVar1 = extraout_v1_00 * 1000 + uVar2;
  if (uVar1 < uVar2) {
    *param_1 = iStack_28 + extraout_v1 + 1;
    uVar1 = uVar1 + 0xc4653600;
  }
  pcVar3 = *(code **)(in_t9 + 0x235534);
  param_1[1] = uVar1;
  (*pcVar3)((int)uVar1 >> 0x1f,uVar1,0,1000000000);
  if (extraout_v1_01 != 0) {
    pcVar3 = *(code **)(in_t9 + 0x235368);
    *param_1 = *param_1 + extraout_v1_01;
    (*pcVar3)((int)uVar1 >> 0x1f,uVar1,0,1000000000);
    param_1[1] = extraout_v1_02;
  }
  return 0;
}

