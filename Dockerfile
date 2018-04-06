FROM vieux/libdragon:conker64

RUN apt-get update && apt-get install -yq git libsox-fmt-all sox

RUN cd /tmp && git clone https://github.com/parasyte/libmikmod-n64.git && cd /tmp/libmikmod-n64 && mkdir build && make && make install && cd /tmp && rm -rf /tmp/libmikmod-n64

COPY . /2048-N64
WORKDIR /2048-N64

RUN mkdir -p filesystem/gfx/sprites/en filesystem/gfx/sprites/fr filesystem/gfx/maps/en filesystem/gfx/maps/fr filesystem/sfx/bgms
RUN make