// func uac_time_secs @ 005242cc size=88

int uac_time_secs(void)

{
  int iVar1;
  timespec local_10;
  
  iVar1 = clock_gettime(1,&local_10);
  if (iVar1 != 0) {
    local_10.tv_sec = time((time_t *)0x0);
  }
  return local_10.tv_sec >> 0x1f;
}

