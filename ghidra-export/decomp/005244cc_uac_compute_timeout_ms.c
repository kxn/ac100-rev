// func uac_compute_timeout_ms @ 005244cc size=328

undefined4 uac_compute_timeout_ms(int *param_1,int param_2)

{
  int extraout_v1;
  int extraout_v1_00;
  int extraout_v1_01;
  int extraout_v1_02;
  uint uVar1;
  uint uVar2;
  timeval local_20;
  
  gettimeofday(&local_20,(__timezone_ptr_t)0x0);
  uVar2 = local_20.tv_usec * 1000;
  param_1[1] = uVar2;
  __udivdi3(param_2 >> 0x1f,param_2,0,1000);
  *param_1 = local_20.tv_sec + extraout_v1;
  __umoddi3(param_2 >> 0x1f,param_2,0,1000);
  uVar1 = extraout_v1_00 * 1000000 + uVar2;
  if (uVar1 < uVar2) {
    *param_1 = local_20.tv_sec + extraout_v1 + 1;
    uVar1 = uVar1 + 0xc4653600;
  }
  param_1[1] = uVar1;
  __udivdi3((int)uVar1 >> 0x1f,uVar1,0,1000000000);
  if (extraout_v1_01 != 0) {
    *param_1 = *param_1 + extraout_v1_01;
    __umoddi3((int)uVar1 >> 0x1f,uVar1,0,1000000000);
    param_1[1] = extraout_v1_02;
  }
  return 0;
}

