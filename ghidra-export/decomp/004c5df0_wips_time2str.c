// func wips_time2str @ 004c5df0 size=72

void wips_time2str(time_t param_1,char *param_2)

{
  time_t local_res0 [4];
  tm tStack_38;
  
  local_res0[0] = param_1;
  localtime_r(local_res0,&tStack_38);
  strftime(param_2,0x19,"%Y-%m-%d %H:%M:%S",&tStack_38);
  return;
}

