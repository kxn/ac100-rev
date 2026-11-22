// func udbg_deadlock_monitor @ 005d2e84 size=124

void udbg_deadlock_monitor(void)

{
  do {
    memset(&task_need_pstack,0,0x200);
    tnp_cnt = 0;
    FUN_00407ee0(_udbg_thread_deadlock_chk);
    if (0 < tnp_cnt) {
      puts("\n======>>The threads stack frame as follow:");
    }
    sleep(tnp_chk_interval);
  } while( true );
}

