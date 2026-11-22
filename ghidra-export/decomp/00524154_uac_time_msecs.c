// func uac_time_msecs @ 00524154 size=188

longlong uac_time_msecs(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  timespec local_20;
  timeval local_18;
  
  iVar2 = clock_gettime(1,&local_20);
  if (iVar2 == 0) {
    uVar3 = 1000000;
    local_18.tv_sec = local_20.tv_sec;
  }
  else {
    gettimeofday(&local_18,(__timezone_ptr_t)0x0);
    uVar3 = 1000;
    local_20.tv_nsec = local_18.tv_usec;
  }
  lVar1 = __udivdi3(local_20.tv_nsec >> 0x1f,local_20.tv_nsec,0,uVar3);
  return (longlong)local_18.tv_sec * 1000 + lVar1;
}

