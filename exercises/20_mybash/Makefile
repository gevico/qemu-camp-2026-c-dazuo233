# =============================================
# 主 Makefile
# 功能：
#   - mybash：生成二进制，放到 bin/
#   - 其他模块（mysed, myfile, mywc, mytrans）：生成静态库 .a，放到 obj/xxx/，.o 放到 obj/xxx/（或 out/，但建议统一）
#   - 所有子模块 Makefile 应支持 OBJDIR 和 BINDIR 参数
# =============================================

PWD := $(shell pwd)

# 所有子模块目录（静态库：生成 .a）
SUBDIRS := \
	mysed \
	myfile \
	mywc \
	mytrans

# 默认目标：构建 mybash（依赖其他库）
all: mybash

$(SUBDIRS):
	$(MAKE) -C src/$@ OBJDIR=$(PWD)/obj/$@

mybash: $(SUBDIRS)
	$(MAKE) -C src/mybash OBJDIR=$(PWD)/obj/mybash BINDIR=$(PWD)/bin LINKLIBS="-L$(PWD)/obj/mysed -L$(PWD)/obj/mywc -L$(PWD)/obj/mytrans -L$(PWD)/obj/myfile -lmysed -lmywc -lmytrans -lmyfile"

clean:
	for d in $(SUBDIRS); do $(MAKE) -C src/$$d clean OBJDIR=$(PWD)/obj/$$d; done
	$(MAKE) -C src/mybash clean OBJDIR=$(PWD)/obj/mybash BINDIR=$(PWD)/bin
	rm -rf obj bin

.PHONY: all $(SUBDIRS) mybash clean