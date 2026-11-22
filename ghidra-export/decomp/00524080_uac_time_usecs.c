// func uac_time_usecs @ 00524080 size=212

longlong uac_time_usecs(void)

{
  longlong lVar1;
  int iVar2;
  timespec local_20;
  timeval local_18;
  
  iVar2 = clock_gettime(1,&local_20);
  if (iVar2 == 0) {
    lVar1 = __udivdi3(local_20.tv_nsec >> 0x1f,local_20.tv_nsec,0,1000);
    lVar1 = (longlong)local_20.tv_sec * 1000000 + lVar1;
  }
  else {
    gettimeofday(&local_18,(__timezone_ptr_t)0x0);
    lVar1 = (longlong)local_18.tv_sec * 1000000 + (longlong)local_18.tv_usec;
  }
  return lVar1;
}

