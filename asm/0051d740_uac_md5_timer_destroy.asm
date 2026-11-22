; func uac_md5_timer_destroy @ 0x0051d740 size=0x44
  51d740:	3c1c0024 	lui	gp,0x24
  51d744:	279c39c0 	addiu	gp,gp,14784
  51d748:	0399e021 	addu	gp,gp,t9
  51d74c:	8f8282ac 	lw	v0,-32084(gp)
  51d750:	27bdffe0 	addiu	sp,sp,-32
  51d754:	8f998620 	lw	t9,-31200(gp)
  51d758:	24050003 	li	a1,3
  51d75c:	afbc0010 	sw	gp,16(sp)
  51d760:	afbf001c 	sw	ra,28(sp)
  51d764:	0320f809 	jalr	t9
  51d768:	8c443b1c 	lw	a0,15132(v0)
  51d76c:	8fbc0010 	lw	gp,16(sp)
  51d770:	8fbf001c 	lw	ra,28(sp)
  51d774:	8f9982f8 	lw	t9,-32008(gp)
  51d778:	2739ca50 	addiu	t9,t9,-13744
  51d77c:	1000fcb4 	b	0x51ca50
  51d780:	27bd0020 	addiu	sp,sp,32
