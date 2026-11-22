// func uac_real_time_secs @ 00524324 size=1

int uac_real_time_secs(void)

{
  int iVar1;
  int in_t9;
  int aiStack_10 [3];
  
  iVar1 = (**(code **)(in_t9 + 0x23557c))(0,aiStack_10);
  if (iVar1 != 0) {
    aiStack_10[0] = (**(code **)(in_t9 + 0x235374))(0);
  }
  return aiStack_10[0] >> 0x1f;
}

