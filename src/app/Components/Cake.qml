import QtQuick
import QtQuick3D

Model {
    id: cake
    rotation: Qt.quaternion(0.707107, 0.707107, 0, 0)
    scale.x: 0.01
    scale.y: 0.01
    scale.z: 0.01
    source: "meshes/cake.mesh"

    PrincipledMaterial {
        id: m_cake_material
        baseColorMap: Texture {
            source: "maps/0.png"
            tilingModeHorizontal: Texture.Repeat
            tilingModeVertical: Texture.Repeat
        }
        opacityChannel: Material.A
        metalnessMap: Texture {
            source: "maps/1.png"
            tilingModeHorizontal: Texture.Repeat
            tilingModeVertical: Texture.Repeat
        }
        metalnessChannel: Material.B
        roughnessMap: Texture {
            source: "maps/1.png"
            tilingModeHorizontal: Texture.Repeat
            tilingModeVertical: Texture.Repeat
        }
        roughnessChannel: Material.G
        metalness: 0
        roughness: 1
        normalMap: Texture {
            source: "maps/2.png"
            tilingModeHorizontal: Texture.Repeat
            tilingModeVertical: Texture.Repeat
        }
        cullMode: Material.NoCulling
    }
    materials: [
        m_cake_material
    ]
}
