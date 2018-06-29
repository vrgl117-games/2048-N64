FROM vieux/libdragon:conker64

RUN apt-get update && apt-get install -yq git libsox-fmt-all sox

RUN cd /tmp && git clone https://github.com/N64-tools/libmikmod.git && cd /tmp/libmikmod/n64 && make --jobs 8 && make install && cd /tmp && rm -rf /tmp/libmikmod

COPY . /2048-N64
WORKDIR /2048-N64

RUN mkdir -p filesystem/gfx/sprites/en filesystem/gfx/sprites/fr  filesystem/gfx/sprites/es filesystem/gfx/maps/en filesystem/gfx/maps/fr filesystem/gfx/maps/es filesystem/sfx/bgms
RUN make