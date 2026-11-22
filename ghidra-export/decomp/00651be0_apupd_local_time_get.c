// func apupd_local_time_get @ 00651be0 size=56

void apupd_local_time_get(tm *param_1)

{
  time_t local_10 [2];
  
  local_10[0] = time((time_t *)0x0);
  localtime_r(local_10,param_1);
  return;
}

