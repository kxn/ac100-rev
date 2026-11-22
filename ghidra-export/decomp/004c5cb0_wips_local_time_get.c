// func wips_local_time_get @ 004c5cb0 size=52

void wips_local_time_get(void)

{
  time_t local_38;
  tm tStack_34;
  
  local_38 = time((time_t *)0x0);
  localtime_r(&local_38,&tStack_34);
  mktime(&tStack_34);
  return;
}

