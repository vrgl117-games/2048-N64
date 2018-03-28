FROM vieux/libdragon:conker64

RUN apt-get update && apt-get install -yq git

RUN cd /tmp && git clone https://github.com/parasyte/libmikmod-n64.git && cd /tmp/libmikmod-n64 && mkdir build && make && make install && cd /tmp && rm -rf /tmp/libmikmod-n64

COPY . /2048-N64
WORKDIR /2048-N64

RUN mkdir -p filesystem/gfx/sprites filesystem/gfx/maps filesystem/sfx/bgms
RUN make