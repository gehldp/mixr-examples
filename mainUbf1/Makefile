#
include ../makedefs

PGM = mainUbf1

#
OBJS = main.o
OBJS += SimStation.o TestDisplay.o
OBJS += TestIoHandler.o factory.o

LDFLAGS += -lmixr_models -lJSBSim
LDFLAGS += -lxbehaviors -lxpanel
LDFLAGS += -lmixr_interop_dis -lmixr_interop -lmixr_graphics -lmixr_ui_glut -lmixr_instruments -lmixr_simulation
LDFLAGS += -lmixr_iodevice
LDFLAGS += -lmixr_ig_cigi -lmixr_ig_viewpoint -lmixr_ig
LDFLAGS += -lmixr_terrain
LDFLAGS += -lJSBSim -lmixr_base
LDFLAGS += -lftgl -lfreetype -lglut -lGLU -lGL -lX11
LDFLAGS += -lcigicl
LDFLAGS += -lpthread -lrt

CPPFLAGS += -I../
LDFLAGS  += -L$(MIXR_LIB_DIR)

EPPFLAGS += -I.

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

edl:
	cpp configs/test00.epp > test00.edl $(EPPFLAGS)

clean:
	-rm -f *.o
	-rm -f *.edl
	-rm -f $(PGM)
