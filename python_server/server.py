from flask import Flask, request, jsonify
import numpy as np
import matplotlib

# Backend sin interfaz gráfica (recomendado en WSL)
matplotlib.use("Agg")

import matplotlib.pyplot as plt
import os
import traceback

app = Flask(__name__)

counter = 0

os.makedirs("images", exist_ok=True)

@app.route('/upload', methods=['POST'])
def upload():
    global counter

    try:
        data = request.get_json()

        if data is None:
            return jsonify({
                "status": "error",
                "message": "No JSON recibido"
            }), 400

        matrix = data["matrix"]

        counter += 1

        matrix_np = np.array(matrix)

        fig, ax = plt.subplots(figsize=(6, 6))

        img = ax.imshow(matrix_np, cmap="viridis")
        fig.colorbar(img)

        filename = f"images/capture_{counter:03d}.png"

        fig.savefig(filename)

        plt.close(fig)

        print(f"Imagen guardada: {filename}")

        return jsonify({
            "status": "ok"
        })

    except Exception as e:
        print("ERROR EN SERVIDOR")
        print(str(e))
        traceback.print_exc()

        return jsonify({
            "status": "error",
            "message": str(e)
        }), 500


if __name__ == '__main__':
    app.run(
        host='127.0.0.1',
        port=5000,
        debug=False,
        use_reloader=False,
        threaded=True
    )
