// func FUN_00524078 @ 00524078 size=8

longlong FUN_00524078(void)

{
  longlong lVar1;
  int iVar2;
  timespec tStack_20;
  timeval tStack_18;
  
  iVar2 = clock_gettime(1,&tStack_20);
  if (iVar2 == 0) {
    lVar1 = __udivdi3(tStack_20.tv_nsec >> 0x1f,tStack_20.tv_nsec,0,1000);
    lVar1 = (longlong)tStack_20.tv_sec * 1000000 + lVar1;
  }
  else {
    gettimeofday(&tStack_18,(__timezone_ptr_t)0x0);
    lVar1 = (longlong)tStack_18.tv_sec * 1000000 + (longlong)tStack_18.tv_usec;
  }
  return lVar1;
}

