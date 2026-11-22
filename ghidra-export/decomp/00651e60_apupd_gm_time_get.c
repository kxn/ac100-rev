// func apupd_gm_time_get @ 00651e60 size=1

void apupd_gm_time_get(undefined4 param_1)

{
  time_t atStack_10 [2];
  
  atStack_10[0] = time((time_t *)0x0);
  func_0x00407ca0(atStack_10,param_1);
  return;
}

